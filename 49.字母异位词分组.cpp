/*
 * @lc app=leetcode.cn id=49 lang=cpp
 *
 * [49] 字母异位词分组
 *
 * https://leetcode-cn.com/problems/group-anagrams/description/
 *
 * algorithms
 * Medium (60.55%)
 * Likes:    275
 * Dislikes: 0
 * Total Accepted:    52.8K
 * Total Submissions: 86.6K
 * Testcase Example:  '["eat","tea","tan","ate","nat","bat"]'
 *
 * 给定一个字符串数组，将字母异位词组合在一起。字母异位词指字母相同，但排列不同的字符串。
 * 
 * 示例:
 * 
 * 输入: ["eat", "tea", "tan", "ate", "nat", "bat"],
 * 输出:
 * [
 * ⁠ ["ate","eat","tea"],
 * ⁠ ["nat","tan"],
 * ⁠ ["bat"]
 * ]
 * 
 * 说明：
 * 
 * 
 * 所有输入均为小写字母。
 * 不考虑答案输出的顺序。
 * 
 * 
 */
#include <unordered_map>
// @lc code=start
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> outs;
        unordered_map<string, vector<string>> map_to_vec;
        for(auto cur_str : strs){
            auto original_str = cur_str;
            sort(cur_str.begin(), cur_str.end());
            auto it = map_to_vec.find(cur_str);
            if(it == map_to_vec.end()){
                map_to_vec[cur_str] = {original_str};
            }
            else{
                it->second.push_back(original_str);
            }
        }
        for(auto item : map_to_vec){
            outs.push_back(item.second);
        }
        return outs;
    }
};
// @lc code=end

