/*
 * @lc app=leetcode.cn id=77 lang=cpp
 *
 * [77] 组合
 *
 * https://leetcode-cn.com/problems/combinations/description/
 *
 * algorithms
 * Medium (72.54%)
 * Likes:    215
 * Dislikes: 0
 * Total Accepted:    33.9K
 * Total Submissions: 46.6K
 * Testcase Example:  '4\n2'
 *
 * 给定两个整数 n 和 k，返回 1 ... n 中所有可能的 k 个数的组合。
 * 
 * 示例:
 * 
 * 输入: n = 4, k = 2
 * 输出:
 * [
 * ⁠ [2,4],
 * ⁠ [3,4],
 * ⁠ [2,3],
 * ⁠ [1,2],
 * ⁠ [1,3],
 * ⁠ [1,4],
 * ]
 * 
 */
#include <list>
// @lc code=start
class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> outs;
        vector<int> nums(n, 0);
        for(int ii = 0; ii < n; ++ii)
            nums[ii] = ii;
        vector<vector<int>> out;
        comb(nums, 0, k, {}, out);
        return out;
    }

    void comb(const vector<int>& nums, int start, int k, vector<int> cur_out, vector<vector<int>>& out){
        if(cur_out.size() == nums.size()){
            out.push_back(cur_out);
            return ;
        }
        for(int ii = start; ++ ii ; ii < nums.size() - k){
            cur_out.push_back(nums[ii]);
            comb(nums, ii + 1, k, cur_out, out);
            cur_out.pop_back();
        }
    }
};
// @lc code=end

