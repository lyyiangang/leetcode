/*
 * @lc app=leetcode.cn id=66 lang=cpp
 *
 * [66] 加一
 *
 * https://leetcode-cn.com/problems/plus-one/description/
 *
 * algorithms
 * Easy (42.86%)
 * Likes:    427
 * Dislikes: 0
 * Total Accepted:    120.2K
 * Total Submissions: 279.1K
 * Testcase Example:  '[1,2,3]'
 *
 * 给定一个由整数组成的非空数组所表示的非负整数，在该数的基础上加一。
 * 
 * 最高位数字存放在数组的首位， 数组中每个元素只存储单个数字。
 * 
 * 你可以假设除了整数 0 之外，这个整数不会以零开头。
 * 
 * 示例 1:
 * 
 * 输入: [1,2,3]
 * 输出: [1,2,4]
 * 解释: 输入数组表示数字 123。
 * 
 * 
 * 示例 2:
 * 
 * 输入: [4,3,2,1]
 * 输出: [4,3,2,2]
 * 解释: 输入数组表示数字 4321。
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int left = 0;
        for(int ii = digits.size() -1; ii >= 0; --ii){
            int val = digits[ii] + left;
            if(ii == digits.size() -1)
                val = digits[ii] + 1 + left;
            if(val >= 10){
                digits[ii] = val % 10;
                left = 1;
            }
            else
            {
                left = 0;
                digits[ii] = val; 
                break;
            }
        }
        if(left == 1){
           vector<int> out(digits.size() +1, 0);
           out[0] = 1;
           copy(digits.begin(), digits.end(), out.begin() + 1);
           return out;
        }
        else
        {
            return digits;
        }
    }
};
// @lc code=end

