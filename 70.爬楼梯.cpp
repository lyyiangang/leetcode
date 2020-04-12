/*
 * @lc app=leetcode.cn id=70 lang=cpp
 *
 * [70] 爬楼梯
 *
 * https://leetcode-cn.com/problems/climbing-stairs/description/
 *
 * algorithms
 * Easy (47.79%)
 * Likes:    850
 * Dislikes: 0
 * Total Accepted:    137.2K
 * Total Submissions: 286.6K
 * Testcase Example:  '2'
 *
 * 假设你正在爬楼梯。需要 n 阶你才能到达楼顶。
 * 
 * 每次你可以爬 1 或 2 个台阶。你有多少种不同的方法可以爬到楼顶呢？
 * 
 * 注意：给定 n 是一个正整数。
 * 
 * 示例 1：
 * 
 * 输入： 2
 * 输出： 2
 * 解释： 有两种方法可以爬到楼顶。
 * 1.  1 阶 + 1 阶
 * 2.  2 阶
 * 
 * 示例 2：
 * 
 * 输入： 3
 * 输出： 3
 * 解释： 有三种方法可以爬到楼顶。
 * 1.  1 阶 + 1 阶 + 1 阶
 * 2.  1 阶 + 2 阶
 * 3.  2 阶 + 1 阶
 * 
 * 
 */

// @lc code=start
// solution中有很多种解法可以参考
class Solution {
public:
    int climbStairs(int n) {
        // return climbRange_recursive(0, n);
        return climb_faibo(1, n);
    }
    int climbRange_recursive(int start, int end){
        if(start > end)
            return 0;
        else if (start == end)
            return 1;
        return climbRange_recursive(start + 1, end) + climbRange_recursive(start + 2, end);
    }
    
    int climb_faibo(int start, int n){
        vector<long> arr(n + 1, 0);
        arr[n] = 1;
        arr[n - 1] = 2;
        for(int ii = n - 2; ii >= 0; --ii){
            arr[ii] = arr[ii + 1] + arr[ii + 2];
        }
        return int(arr[start]);
    }
};
// @lc code=end

