/*
 * @lc app=leetcode.cn id=79 lang=cpp
 *
 * [79] 单词搜索
 *
 * https://leetcode-cn.com/problems/word-search/description/
 *
 * algorithms
 * Medium (40.33%)
 * Likes:    310
 * Dislikes: 0
 * Total Accepted:    37K
 * Total Submissions: 91.3K
 * Testcase Example:  '[["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]]\n"ABCCED"'
 *
 * 给定一个二维网格和一个单词，找出该单词是否存在于网格中。
 * 
 * 单词必须按照字母顺序，通过相邻的单元格内的字母构成，其中“相邻”单元格是那些水平相邻或垂直相邻的单元格。同一个单元格内的字母不允许被重复使用。
 * 
 * 示例:
 * 
 * board =
 * [
 * ⁠ ['A','B','C','E'],
 * ⁠ ['S','F','C','S'],
 * ⁠ ['A','D','E','E']
 * ]
 * 
 * 给定 word = "ABCCED", 返回 true.
 * 给定 word = "SEE", 返回 true.
 * 给定 word = "ABCB", 返回 false.
 * 
 */

// @lc code=start
class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        vector<vector<bool>> mask(board.size());
        for(int ii = 0; ii < mask.size(); ++ii){
            mask[ii].resize(board.front().size(), true);
        }
        for(int rr = 0; rr < board.size(); ++rr){
            for(int cc = 0; cc < board[rr].size(); ++cc){
                if(board[rr][cc] == word[0]){
                    bool exist = backtrace(board, word, rr, cc, 1, mask);
                    if(exist)
                        return true;
                }
            }
        }
    }

    void backtrace(vector<vector<char>& board, string word, int rr, int cc, int next_char_idx, vector<vector<bool>> mask){
        vector<vector<int, int>> test_idxs ={
            {rr -1, cc -1},
            {rr -1, cc + 1},
            {rr + 1, cc -1},
            {rr +1, cc + 1},
        };
        int R = board.size(), C = board.front().size();
        bool equal = true;
        for(auto rc : test_idxs){
            int rr = rc[0], cc = rc[1];
            if(rr >= 0 && rr < R)

        }
        if((board[test_rr][test_cc] == word[next_char_idx] && mask[test_rr][test_cc]) ||
    }
};
// @lc code=end

