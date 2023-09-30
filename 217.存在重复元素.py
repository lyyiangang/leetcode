#
# @lc app=leetcode.cn id=217 lang=python3
#
# [217] 存在重复元素
#

# @lc code=start
class Solution:
    def containsDuplicate(self, nums: List[int]) -> bool:
        num_set = set()
        for val in nums:
            if val in num_set:
                return True
            num_set.add(val)
        return False
# @lc code=end

