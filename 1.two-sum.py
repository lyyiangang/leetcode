#
# @lc app=leetcode id=1 lang=python
#
# [1] Two Sum
#
class Solution(object):
    def twoSum(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: List[int]
        """
        # cnt = len(nums)
        # for ii in range(cnt - 1):
        #     for jj in range(ii + 1, cnt):
        #         if nums[ii] + nums[jj] == target:
        #             return [ii, jj]

        # solution 2
        val_to_ind = {k:v for k, v in zip(nums, range(len(nums)))}
        for ii in range(len(nums)-1):
            val = target - nums[ii]
            if val in val_to_ind and val_to_ind[val] != ii:
                return [ii, val_to_ind[val]]

# ss = Solution()
# print(ss.twoSum([3, 2, 4], 6))