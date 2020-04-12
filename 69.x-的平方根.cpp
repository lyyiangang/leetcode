/*
 * @lc app=leetcode.cn id=69 lang=cpp
 *
 * [69] x 的平方根
 *
 * https://leetcode-cn.com/problems/sqrtx/description/
 *
 * algorithms
 * Easy (37.51%)
 * Likes:    306
 * Dislikes: 0
 * Total Accepted:    95.5K
 * Total Submissions: 254.4K
 * Testcase Example:  '4'
 *
 * 实现 int sqrt(int x) 函数。
 * 
 * 计算并返回 x 的平方根，其中 x 是非负整数。
 * 
 * 由于返回类型是整数，结果只保留整数的部分，小数部分将被舍去。
 * 
 * 示例 1:
 * 
 * 输入: 4
 * 输出: 2
 * 
 * 
 * 示例 2:
 * 
 * 输入: 8
 * 输出: 2
 * 说明: 8 的平方根是 2.82842..., 
 * 由于返回类型是整数，小数部分将被舍去。
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    int mySqrt(int x){
        // x^(1/2) = x/2 --> x = x^2/4  --> x^2 - 4x = 0 -->x(x-4)=0
        if (x < 2) return x;

        int left = 2, right = x / 2;
        while (left <= right) {
            int pivot = left + (right - left) / 2;
            long num = (long)pivot * pivot;
            if (num > x) 
                right = pivot - 1;
            else if 
                (num < x) left = pivot + 1;
            else 
                return pivot;
        }

        return right;
    }
    // int mySqrt(int x) {
    //     //https://blog.csdn.net/coolwriter/article/details/79036524
    //     // y = x^(1/2) --> y^2 - x = 0 --> f(y) = y^2 - x
    //     // f'(y) = 2y, f'(y0) = f(y0)/(y0 - y1) --> y1 = y0 - f(y0)/f'(y0)
    //     if(x == 0)
    //         return 0;
    //     double y0 = x;
    //     while(true){
    //        double y1 = y0 - (y0 * y0 - x)/(2 * y0);
    //     //    cout<<y1<<" ";
    //        if(std::abs(y1 - y0) < 1.0e-6)
    //             break;
    //         y0 = y1;
    //     };
    //     return int(std::floor(y0));
    // }
};
// @lc code=end

