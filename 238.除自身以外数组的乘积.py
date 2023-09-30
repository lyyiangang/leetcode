#
# @lc app=leetcode.cn id=238 lang=python3
#
# [238] 除自身以外数组的乘积
#

# @lc code=start
class Solution:
    def productExceptSelf(self, nums: List[int]) -> List[int]:
        return self.method_A(nums)

    def method_A(self, nums):
        # 空间复杂度O(2N)[忽略输出数组ans占用空间]
        n = len(nums)
        pre_mul = [1] * n # 前缀积, pre_mul[i] 保存的是num[0] * num[1] *...num[i-1]
        post_mul = [1] * n # 后缀积, post_mul[i] 保存的为num[i+1] * num[i+2]*...*num[n-1]
        for idx in range(1, n, 1):
            pre_mul[idx] = pre_mul[idx - 1] * nums[idx - 1]
        for idx in range(n-2, -1, -1):
            post_mul[idx] = post_mul[idx + 1] * nums[idx + 1]
        ans = [0] * n
        for idx in range(n):
            ans[idx] = pre_mul[idx] * post_mul[idx]
        return ans

        
# @lc code=end

