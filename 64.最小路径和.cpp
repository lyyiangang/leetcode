/*
 * @lc app=leetcode.cn id=64 lang=cpp
 *
 * [64] 最小路径和
 *
 * https://leetcode-cn.com/problems/minimum-path-sum/description/
 *
 * algorithms
 * Medium (64.46%)
 * Likes:    387
 * Dislikes: 0
 * Total Accepted:    59.8K
 * Total Submissions: 92.4K
 * Testcase Example:  '[[1,3,1],[1,5,1],[4,2,1]]'
 *
 * 给定一个包含非负整数的 m x n 网格，请找出一条从左上角到右下角的路径，使得路径上的数字总和为最小。
 * 
 * 说明：每次只能向下或者向右移动一步。
 * 
 * 示例:
 * 
 * 输入:
 * [
 * [1,3,1],
 * ⁠ [1,5,1],
 * ⁠ [4,2,1]
 * ]
 * 输出: 7
 * 解释: 因为路径 1→3→1→1→1 的总和最小。
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid.front().size();
        vector<vector<int>> dp(m, vector<int>(n, 0));
        dp[0][0] = grid[0][0];
        for(int ii = 1; ii < m; ++ii){
            dp[ii][0] = grid[ii][0] + dp[ii -1][0];
        }
        for(int ii = 1; ii < n; ++ii){
            dp[0][ii] = grid[0][ii] + dp[0][ii -1];
        }
        for(int rr = 1; rr < m; ++ rr){
            for(int cc = 1; cc < n; ++cc){
                int path_left = dp[rr][cc - 1] + grid[rr][cc];
                int path_top = dp[rr -1][cc] + grid[rr][cc];
                dp[rr][cc] = min(path_left, path_top);
            }
        }
        return dp[m - 1][n - 1];
    }
};
// @lc code=end

