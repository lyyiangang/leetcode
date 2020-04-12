/*
 * @lc app=leetcode.cn id=36 lang=cpp
 *
 * [36] 有效的数独
 *
 * https://leetcode-cn.com/problems/valid-sudoku/description/
 *
 * algorithms
 * Medium (58.18%)
 * Likes:    271
 * Dislikes: 0
 * Total Accepted:    55.9K
 * Total Submissions: 95.7K
 * Testcase Example:  '[["5","3",".",".","7",".",".",".","."],["6",".",".","1","9","5",".",".","."],[".","9","8",".",".",".",".","6","."],["8",".",".",".","6",".",".",".","3"],["4",".",".","8",".","3",".",".","1"],["7",".",".",".","2",".",".",".","6"],[".","6",".",".",".",".","2","8","."],[".",".",".","4","1","9",".",".","5"],[".",".",".",".","8",".",".","7","9"]]'
 *
 * 判断一个 9x9 的数独是否有效。只需要根据以下规则，验证已经填入的数字是否有效即可。
 * 
 * 
 * 数字 1-9 在每一行只能出现一次。
 * 数字 1-9 在每一列只能出现一次。
 * 数字 1-9 在每一个以粗实线分隔的 3x3 宫内只能出现一次。
 * 
 * 
 * 
 * 
 * 上图是一个部分填充的有效的数独。
 * 
 * 数独部分空格内已填入了数字，空白格用 '.' 表示。
 * 
 * 示例 1:
 * 
 * 输入:
 * [
 * ⁠ ["5","3",".",".","7",".",".",".","."],
 * ⁠ ["6",".",".","1","9","5",".",".","."],
 * ⁠ [".","9","8",".",".",".",".","6","."],
 * ⁠ ["8",".",".",".","6",".",".",".","3"],
 * ⁠ ["4",".",".","8",".","3",".",".","1"],
 * ⁠ ["7",".",".",".","2",".",".",".","6"],
 * ⁠ [".","6",".",".",".",".","2","8","."],
 * ⁠ [".",".",".","4","1","9",".",".","5"],
 * ⁠ [".",".",".",".","8",".",".","7","9"]
 * ]
 * 输出: true
 * 
 * 
 * 示例 2:
 * 
 * 输入:
 * [
 * ["8","3",".",".","7",".",".",".","."],
 * ["6",".",".","1","9","5",".",".","."],
 * [".","9","8",".",".",".",".","6","."],
 * ["8",".",".",".","6",".",".",".","3"],
 * ["4",".",".","8",".","3",".",".","1"],
 * ["7",".",".",".","2",".",".",".","6"],
 * [".","6",".",".",".",".","2","8","."],
 * [".",".",".","4","1","9",".",".","5"],
 * [".",".",".",".","8",".",".","7","9"]
 * ]
 * 输出: false
 * 解释: 除了第一行的第一个数字从 5 改为 8 以外，空格内其他数字均与 示例1 相同。
 * ⁠    但由于位于左上角的 3x3 宫内有两个 8 存在, 因此这个数独是无效的。
 * 
 * 说明:
 * 
 * 
 * 一个有效的数独（部分已被填充）不一定是可解的。
 * 只需要根据以上规则，验证已经填入的数字是否有效即可。
 * 给定数独序列只包含数字 1-9 和字符 '.' 。
 * 给定数独永远是 9x9 形式的。
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        vector<int> tmp_num_map(10, 0);
        vector<vector<int>> cc_map(9,tmp_num_map);
        vector<vector<int>> cur_cells(3, tmp_num_map);
        for(int rr = 0; rr < board.size(); ++rr){
            vector<int> rr_map(10, 0);
            if(rr % 3 == 0){
                cur_cells.clear();
                cur_cells.resize(3, tmp_num_map);
                // cout<<"resize cells"<<endl;
            }
            for(int cc = 0; cc < board[rr].size(); ++cc){
                char val = board[rr][cc];
                int num = -1;
                if(val >= '1' && val <= '9'){
                    num = int(val - '1') + 1;
                }
                else
                    continue;
                // cout<<"rr,cc:"<<rr<<" "<<cc<<" val "<<val<<endl; 
                // check row
                if(rr_map[num] >0)
                    return false;
                else
                    ++ rr_map[num];
                // check column
                if(cc_map[cc][num] > 0)
                    return false;
                else 
                    ++ cc_map[cc][num];
                // cells check
                int icell = cc / 3;
                // cout<<"cell:"<< cur_cells[icell][num]<<endl;
                if(cur_cells[icell][num]>0)
                    return false;
                else
                    ++ cur_cells[icell][num]; 
            }
        }
        return true;
    }
};
// @lc code=end

