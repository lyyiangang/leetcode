/*
 * @lc app=leetcode.cn id=5 lang=cpp
 *
 * [5] 最长回文子串
 *
 * https://leetcode-cn.com/problems/longest-palindromic-substring/description/
 *
 * algorithms
 * Medium (28.40%)
 * Likes:    1734
 * Dislikes: 0
 * Total Accepted:    178.9K
 * Total Submissions: 629.6K
 * Testcase Example:  '"babad"'
 *
 * 给定一个字符串 s，找到 s 中最长的回文子串。你可以假设 s 的最大长度为 1000。
 * 
 * 示例 1：
 * 
 * 输入: "babad"
 * 输出: "bab"
 * 注意: "aba" 也是一个有效答案。
 * 
 * 
 * 示例 2：
 * 
 * 输入: "cbbd"
 * 输出: "bb"
 * 
 * 
 */
// @lc code=start
class Solution {
public:
    string longestPalindrome(string s) {
        if(s.size() < 2)
            return s;
       auto symmetry = [](const std::string& ss, int start, int end, int* sub_str_start){
           // mode ss.substr(start, len);
           int ii = start, kk = end;
            while(ii >= 0 && kk < ss.size())
            {
                if(ss[ii] != ss[kk])
                    break;
                --ii;
                ++kk;
            };
            *sub_str_start = ii + 1;
            return (kk - end) * 2;
       };
       string out;
       for(int ii = 0; ii < s.size(); ++ii)
       {
           int sub_start_a = 0, sub_start_b = 0;
           int len_a = symmetry(s, ii - 1, ii, &sub_start_a);
           int len_b = symmetry(s, ii-1, ii + 1, &sub_start_b) + 1;
           if(int(out.size()) >= std::max(len_a, len_b))
                continue;
            else
            {
                if(len_a > len_b)
                    out = s.substr(sub_start_a, len_a);
                else
                    out = s.substr(sub_start_b, len_b);
            }
        }        
       return out;
    }
};
// @lc code=end

