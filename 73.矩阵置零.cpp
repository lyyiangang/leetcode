/*
 * @lc app=leetcode.cn id=73 lang=cpp
 *
 * [73] 矩阵置零
 *
 * https://leetcode-cn.com/problems/set-matrix-zeroes/description/
 *
 * algorithms
 * Medium (54.99%)
 * Likes:    184
 * Dislikes: 0
 * Total Accepted:    30.4K
 * Total Submissions: 55.1K
 * Testcase Example:  '[[1,1,1],[1,0,1],[1,1,1]]'
 *
 * 给定一个 m x n 的矩阵，如果一个元素为 0，则将其所在行和列的所有元素都设为 0。请使用原地算法。
 * 
 * 示例 1:
 * 
 * 输入: 
 * [
 * [1,1,1],
 * [1,0,1],
 * [1,1,1]
 * ]
 * 输出: 
 * [
 * [1,0,1],
 * [0,0,0],
 * [1,0,1]
 * ]
 * 
 * 
 * 示例 2:
 * 
 * 输入: 
 * [
 * [0,1,2,0],
 * [3,4,5,2],
 * [1,3,1,5]
 * ]
 * 输出: 
 * [
 * [0,0,0,0],
 * [0,4,5,0],
 * [0,3,1,0]
 * ]
 * 
 * 进阶:
 * 
 * 
 * 一个直接的解决方案是使用  O(mn) 的额外空间，但这并不是一个好的解决方案。
 * 一个简单的改进方案是使用 O(m + n) 的额外空间，但这仍然不是最好的解决方案。
 * 你能想出一个常数空间的解决方案吗？
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix.front().size();
        vector<bool> r_zeros(m, false), c_zeros(n, false);
        for(int rr = 0; rr < m; ++rr){
            for(int cc = 0; cc < n; ++ cc){
                if(matrix[rr][cc] == 0){
                    r_zeros[rr] = true;
                    c_zeros[cc] = true;
                }
            }
        }

        for(int rr = 0; rr < m; ++rr){
            for(int cc = 0; cc < n; ++ cc){
                if(r_zeros[rr])
                    matrix[rr][cc] = 0;
                else if(c_zeros[cc]){
                    matrix[rr][cc] = 0;
                }
            }
        }
    }
};
// @lc code=end

