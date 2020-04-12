/*
 * @lc app=leetcode.cn id=46 lang=cpp
 *
 * [46] 全排列
 *
 * https://leetcode-cn.com/problems/permutations/description/
 *
 * algorithms
 * Medium (73.86%)
 * Likes:    529
 * Dislikes: 0
 * Total Accepted:    77K
 * Total Submissions: 104.1K
 * Testcase Example:  '[1,2,3]'
 *
 * 给定一个没有重复数字的序列，返回其所有可能的全排列。
 * 
 * 示例:
 * 
 * 输入: [1,2,3]
 * 输出:
 * [
 * ⁠ [1,2,3],
 * ⁠ [1,3,2],
 * ⁠ [2,1,3],
 * ⁠ [2,3,1],
 * ⁠ [3,1,2],
 * ⁠ [3,2,1]
 * ]
 * 
 */

// @lc code=start
class Solution {
public:
    // vector<vector<int>> permute(vector<int>& nums) {
    //    // Cn1*C(n-1)1*C(n-2)1*... 
    //     std::vector<bool> mask;
    //     mask.resize(nums.size(), true);
    //     vector<vector<int>> outs;
    //     vector<int> pre_out;
    //     perm(nums, mask, pre_out, outs);
    //     return outs;
    // }

    // void perm(vector<int>& nums, const vector<bool>& mask, vector<int> pre_out, vector<vector<int>>& outs){
    //     if(pre_out.size() == nums.size())
    //     {
    //        outs.push_back(pre_out);
    //        return; 
    //     }
    //     for(int ii = 0; ii < nums.size(); ++ii)
    //     {
    //         if(!mask[ii])
    //             continue;
    //         auto cur_out = pre_out;
    //         cur_out.push_back(nums[ii]);
    //         auto cur_mask = mask;
    //         cur_mask[ii] = false;
    //         perm(nums, cur_mask, cur_out, outs);
    //     }
    // }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> outs;
        vector<int> cur_out;
        perm(nums, 0, cur_out, outs);
        return outs;
    }

    void perm(vector<int> nums, int start, vector<int> cur_out, vector<vector<int>>& outs){
        if(cur_out.size() == nums.size())
        {
            outs.push_back(cur_out);
            return;
        }
        for(int ii = start; ii < nums.size(); ++ii){
            cur_out.push_back(nums[ii]);
            swap(nums[ii], nums[start]);
            perm(nums, ii + 1, cur_out, outs);
            swap(nums[ii], nums[start]);
        } 
    }
};
// @lc code=end

