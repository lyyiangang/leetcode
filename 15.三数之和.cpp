/*
 * @lc app=leetcode.cn id=15 lang=cpp
 *
 * [15] 三数之和
 *
 * https://leetcode-cn.com/problems/3sum/description/
 *
 * algorithms
 * Medium (25.40%)
 * Likes:    1785
 * Dislikes: 0
 * Total Accepted:    154.8K
 * Total Submissions: 608.6K
 * Testcase Example:  '[-1,0,1,2,-1,-4]'
 *
 * 给定一个包含 n 个整数的数组 nums，判断 nums 中是否存在三个元素 a，b，c ，使得 a + b + c = 0
 * ？找出所有满足条件且不重复的三元组。
 * 
 * 注意：答案中不可以包含重复的三元组。
 * 
 * 
 * 
 * 示例：
 * 
 * 给定数组 nums = [-1, 0, 1, 2, -1, -4]，
 * 
 * 满足要求的三元组集合为：
 * [
 * ⁠ [-1, 0, 1],
 * ⁠ [-1, -1, 2]
 * ]
 * 
 * 
 */
#include <sstream>
#include <unordered_set>
// @lc code=start
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        // reference doc: https://leetcode-cn.com/problems/3sum/solution/pai-xu-shuang-zhi-zhen-zhu-xing-jie-shi-python3-by/
        // a>=b>=c 
        // a >= 0
        // c <= 0
        // b in [a, c]       
        vector<vector<int>> ans;
        if(nums.size() < 3)
            return ans;
       sort(nums.begin(), nums.end());
       // [-2,0,1,1,2]
       for(int ic = 0; ic <= nums.size() - 3; ++ic)
       {
            if(nums[ic] > 0)
                break;
            if(ic > 0 && nums[ic] == nums[ic - 1])
                continue;
            int left = ic + 1, right = nums.size() -1;
            while(left < right)
            {
                // printf("%d %d %d\n", ic, left, right);
                int sum = nums[ic] + nums[left] + nums[right];
                if(sum == 0)
                {
                   ans.push_back({nums[ic], nums[left], nums[right]});
                   while(left < right)
                   {
                       if(nums[left] == nums[left + 1])
                            ++left;
                       else
                       {
                           ++left;
                           break;
                       }
                   };
                   while(left < right)
                   {
                       if(nums[right] == nums[right-1])
                            --right;
                        else
                        {
                            --right;
                            break;
                        }
                   };
                }
                else if (sum > 0)
                    --right;
                else
                    ++left;
            };
       } 
       return ans;
    }
};
// @lc code=end

