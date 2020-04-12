/*
 * @lc app=leetcode.cn id=1 lang=cpp
 *
 * [1] 两数之和
 *
 * https://leetcode-cn.com/problems/two-sum/description/
 *
 * algorithms
 * Easy (47.52%)
 * Likes:    7848
 * Dislikes: 0
 * Total Accepted:    900.1K
 * Total Submissions: 1.9M
 * Testcase Example:  '[2,7,11,15]\n9'
 *
 * 给定一个整数数组 nums 和一个目标值 target，请你在该数组中找出和为目标值的那 两个 整数，并返回他们的数组下标。
 * 
 * 你可以假设每种输入只会对应一个答案。但是，你不能重复利用这个数组中同样的元素。
 * 
 * 示例:
 * 
 * 给定 nums = [2, 7, 11, 15], target = 9
 * 
 * 因为 nums[0] + nums[1] = 2 + 7 = 9
 * 所以返回 [0, 1]
 * 
 * 
 */
#include <unordered_map>
// @lc code=start
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        // vector<int> results;
        // // if(nums.size() < 2)
        // //     return results;
        // unordered_map<int, int> val_to_idx_map;
        // for(int ii = 0; ii < nums.size(); ++ii){
        //     int val = nums[ii];
        //     int desire = target - val;
        //     auto it = val_to_idx_map.find(desire);
        //     if(it != val_to_idx_map.end()){
        //         results.push_back(ii);
        //         results.push_back(it->second);
        //         break;
        //     }
        //     val_to_idx_map[val] = ii;
        // } 
        // return results;
        unordered_map<int, int> val_to_idx_map;
        for(int ii = 0; ii < nums.size(); ++ii){
            val_to_idx_map[nums[ii]] = ii;
        }
        for(int ii = 0; ii < nums.size(); ++ii){
            int desire = target - nums[ii];
            auto it = val_to_idx_map.find(desire);
            if(it != val_to_idx_map.end() && it->second != ii){
                return {ii, it->second};
            }
        }
        return {};
    }
};
// @lc code=end

