/*
 * @lc app=leetcode.cn id=56 lang=cpp
 *
 * [56] 合并区间
 *
 * https://leetcode-cn.com/problems/merge-intervals/description/
 *
 * algorithms
 * Medium (40.13%)
 * Likes:    299
 * Dislikes: 0
 * Total Accepted:    56.1K
 * Total Submissions: 138.7K
 * Testcase Example:  '[[1,3],[2,6],[8,10],[15,18]]'
 *
 * 给出一个区间的集合，请合并所有重叠的区间。
 * 
 * 示例 1:
 * 
 * 输入: [[1,3],[2,6],[8,10],[15,18]]
 * 输出: [[1,6],[8,10],[15,18]]
 * 解释: 区间 [1,3] 和 [2,6] 重叠, 将它们合并为 [1,6].
 * 
 * 
 * 示例 2:
 * 
 * 输入: [[1,4],[4,5]]
 * 输出: [[1,5]]
 * 解释: 区间 [1,4] 和 [4,5] 可被视为重叠区间。
 * 
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> outs;
        auto cmp = [](const vector<int>& val1, const vector<int>& val2){
            return val1[0] < val2[0];
        };
        sort(intervals.begin(), intervals.end(), cmp);
        auto intersect = [](const vector<int>& inter_left, const vector<int>& inter_right){
            if(inter_right[0] >= inter_left[0] && inter_right[0] <= inter_left[1]){
                return vector<int>{inter_left[0], max(inter_left[1], inter_right[1])};
            }             
            return vector<int>{};
        };
        int idx = 0;
        while(idx < intervals.size()){
            if(outs.empty()){
                outs.push_back(intervals[idx]);
            }
            else{
                vector<int> merged = intersect(outs.back(), intervals[idx]);
                if(merged.empty()){
                    outs.push_back(intervals[idx]); 
                }
                else{
                    outs[outs.size() -1] = merged;
                }
            }
            ++ idx;
        }
        return outs;
    }
};
// @lc code=end

