/*
 * @lc app=leetcode.cn id=7 lang=cpp
 *
 * [7] 整数反转
 *
 * https://leetcode-cn.com/problems/reverse-integer/description/
 *
 * algorithms
 * Easy (33.60%)
 * Likes:    1745
 * Dislikes: 0
 * Total Accepted:    299K
 * Total Submissions: 883.6K
 * Testcase Example:  '123'
 *
 * 给出一个 32 位的有符号整数，你需要将这个整数中每位上的数字进行反转。
 * 
 * 示例 1:
 * 
 * 输入: 123
 * 输出: 321
 * 
 * 
 * 示例 2:
 * 
 * 输入: -123
 * 输出: -321
 * 
 * 
 * 示例 3:
 * 
 * 输入: 120
 * 输出: 21
 * 
 * 
 * 注意:
 * 
 * 假设我们的环境只能存储得下 32 位的有符号整数，则其数值范围为 [−2^31,  2^31 − 1]。请根据这个假设，如果反转后整数溢出那么就返回
 * 0。
 * 
 */

// @lc code=start
class Solution {
public:
    int reverse(int x) {
        // auto dump_arr = [](const vector<int>& arr){
        //     for(int v : arr){
        //         cout<<v<<" ";
        //     }
        // };
        // vector<int> arr = {2, 3, 9, 0, 8, 5};
        // vector<int> backup_arr = arr;
        // sort(backup_arr.begin(), backup_arr.end());
        test();
        return 0;
    }
    void test(){
        class Person{
            public:
                Person(){
                    Say();
                } // 1
                virtual void Say(){cout<<"say"<<endl;}
                int age; // 4
        };
        Person p;

    }
    int method(int x){
        int sign = x > 0 ? 1 : -1;
        long sum = 0;
        do{
            int val = x % 10;
            sum *= 10;
            // if(sign < 0 && sum > -1 *(INT_MIN / 10) ||
            //     sign > 0 && sum > (INT_MAX / 10))
            //     return 0;
            // if(sum == -1* (INT_MIN / 10) && val > (-1 * INT_MIN % 10) ||
            //     sum == INT_MAX / 10 && val > INT_MAX % 10)
            //         return 0;
            sum += val;
            x = x / 10;
        }while(x != 0);
        if(sum > INT_MAX || sum < INT_MIN)
            return 0;
        return sum;
    }
};
// @lc code=end

