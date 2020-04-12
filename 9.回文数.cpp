/*
 * @lc app=leetcode.cn id=9 lang=cpp
 *
 * [9] 回文数
 *
 * https://leetcode-cn.com/problems/palindrome-number/description/
 *
 * algorithms
 * Easy (57.07%)
 * Likes:    931
 * Dislikes: 0
 * Total Accepted:    246.7K
 * Total Submissions: 432.2K
 * Testcase Example:  '121'
 *
 * 判断一个整数是否是回文数。回文数是指正序（从左向右）和倒序（从右向左）读都是一样的整数。
 * 
 * 示例 1:
 * 
 * 输入: 121
 * 输出: true
 * 
 * 
 * 示例 2:
 * 
 * 输入: -121
 * 输出: false
 * 解释: 从左向右读, 为 -121 。 从右向左读, 为 121- 。因此它不是一个回文数。
 * 
 * 
 * 示例 3:
 * 
 * 输入: 10
 * 输出: false
 * 解释: 从右向左读, 为 01 。因此它不是一个回文数。
 * 
 * 
 * 进阶:
 * 
 * 你能不将整数转为字符串来解决这个问题吗？
 * 
 */

// @lc code=start
class Solution {
public:
    bool isPalindrome(int x) {
        if(x < 0)
            return false;
        std::vector<int> vec;
        while(x > 0)
        {
            vec.push_back(x % 10);
            x = x/10;
        };
        if(vec.size() < 2)
           return true; 
      int i_s = 0, i_e = vec.size() -1; 
      while(i_e >= i_s)
      {
          if(vec[i_e] != vec[i_s])
            return false;
          ++i_s;
          --i_e;
      };
      return true;
    }
};
// @lc code=end

