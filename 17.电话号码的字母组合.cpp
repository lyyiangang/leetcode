/*
 * @lc app=leetcode.cn id=17 lang=cpp
 *
 * [17] 电话号码的字母组合
 *
 * https://leetcode-cn.com/problems/letter-combinations-of-a-phone-number/description/
 *
 * algorithms
 * Medium (52.34%)
 * Likes:    574
 * Dislikes: 0
 * Total Accepted:    77K
 * Total Submissions: 146.8K
 * Testcase Example:  '"23"'
 *
 * 给定一个仅包含数字 2-9 的字符串，返回所有它能表示的字母组合。
 * 
 * 给出数字到字母的映射如下（与电话按键相同）。注意 1 不对应任何字母。
 * 
 * 
 * 
 * 示例:
 * 
 * 输入："23"
 * 输出：["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"].
 * 
 * 
 * 说明:
 * 尽管上面的答案是按字典序排列的，但是你可以任意选择答案输出的顺序。
 * 
 */

// @lc code=start
#include <unordered_map>

class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector<string> outs;
        if(digits.empty())
            return outs;
        combination("", digits, 0, outs);
        return outs;
    
    }
    void combination (string init_str, string digits, int idx, vector<string>& outs){
            if(idx == digits.size())
            {
                outs.push_back(init_str);
                return;
            }
            vector<string> digit_to_char_vec = {
                "",
                "",
                "abc",
                "def",
                "ghi",
                "jkl",
                "mno",
                "pqrs",
                "tuv",
                "wxyz",
            };
            int digit_val = digits[idx] - '0';
            for(char cc : digit_to_char_vec[digit_val]){
                combination(init_str + string(1, cc), digits, idx + 1, outs);
            }
    }
};
// @lc code=end

