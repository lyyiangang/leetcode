/*
 * @lc app=leetcode.cn id=28 lang=cpp
 *
 * [28] 实现 strStr()
 *
 * https://leetcode-cn.com/problems/implement-strstr/description/
 *
 * algorithms
 * Easy (39.48%)
 * Likes:    363
 * Dislikes: 0
 * Total Accepted:    127.5K
 * Total Submissions: 322.7K
 * Testcase Example:  '"hello"\n"ll"'
 *
 * 实现 strStr() 函数。
 * 
 * 给定一个 haystack 字符串和一个 needle 字符串，在 haystack 字符串中找出 needle 字符串出现的第一个位置
 * (从0开始)。如果不存在，则返回  -1。
 * 
 * 示例 1:
 * 
 * 输入: haystack = "hello", needle = "ll"
 * 输出: 2
 * 
 * 
 * 示例 2:
 * 
 * 输入: haystack = "aaaaa", needle = "bba"
 * 输出: -1
 * 
 * 
 * 说明:
 * 
 * 当 needle 是空字符串时，我们应当返回什么值呢？这是一个在面试中很好的问题。
 * 
 * 对于本题而言，当 needle 是空字符串时我们应当返回 0 。这与C语言的 strstr() 以及 Java的 indexOf() 定义相符。
 * 
 */

// @lc code=start
class Solution {
public:
    int strStr(string haystack, string needle) {
        if(needle.empty())
            return 0;
        int idx = -1;
        for(int ii = 0; ii < haystack.size(); ++ii)
        {
            bool contain = true;
            int start_idx = ii;
            for(int kk = 0; kk < needle.size(); ++kk, ++ start_idx)
            {
                if(start_idx >= haystack.size() || haystack[start_idx] != needle[kk])
                {
                    contain = false;
                    break;
                }
            }
            if(contain)
            {
                idx = ii;
                break;
            }
        }
        return idx;
    }
};
// @lc code=end

