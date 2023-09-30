#
# @lc app=leetcode.cn id=53 lang=python3
#
# [53] 最大子数组和
#

# @lc code=start
"""
到某个item时, 它有两种选择,
1. 和前面的数组连的上,那么这是dp的值为dp+val
2. 和前面的数组连不上, 那么dp为val
这个dp表示的是以nums[0:i]范围的数组的最大子数组和.

dp = 0
for val in nums:
    dp = max(val, dp + val)
"""
class Solution:
    def maxSubArray(self, nums: List[int]) -> int:
        import math
        max_ans = -math.inf
        dp = 0
        for val in nums:
            dp = max(val, dp + val)
            max_ans = max(dp, max_ans) 
        return max_ans
# @lc code=end

