/*
 * @lc app=leetcode.cn id=3 lang=cpp
 *
 * [3] 无重复字符的最长子串
 */

// @lc code=start
#include <unordered_set>
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        return slide_window_v2(s);
        // return slide_window(s);
        // if(s.empty())
        //     return 0;
        // int max_unique = INT_MIN;
        // for(int ii = 0; ii < s.size(); ++ii)
        // {
        //     std::unordered_set<char> cur_set;
        //     int cur_max = 0;
        //     for(int kk = ii; kk < s.size(); ++kk)
        //     {
        //         char c = s[kk];
        //         if(cur_set.find(c) == cur_set.end())
        //         {
        //             cur_set.insert(c);
        //             ++ cur_max;
        //         }
        //         else
        //         {
        //             break;
        //         }
        //     }
        //     max_unique = std::max(max_unique, cur_max);
        //     //cout<<" max_uni:"<<max_unique<<" ";
        // }        
        // return max_unique;
    }
    int slide_window_v2(string s){
        int max_len = 0;
        int left = 0, right = 0;
        unordered_set<char> s_map;
        while(left < s.size() && right < s.size()){
            if(s_map.find(s[right]) == s_map.end()){
                s_map.insert(s[right]);
                max_len = max(max_len, right - left + 1);
                ++ right;
            }
            else{
                s_map.erase(s[left]);
                ++ left;
            }
        };
        return max_len;
    }











    int slide_window(string s){
        int ans = 0, i = 0, j = 0;
        std::unordered_set<char> s_set;
        while(i < s.size() && j < s.size())
        {
            char cc = s[j];
            if(s_set.find(cc) == s_set.end())
            {
                s_set.insert(cc);
                ans = std::max(ans, j - i + 1);
                ++j;
            }
            else
            {
                s_set.erase(s[i]);
                ++i;
            }
        };
        return ans;
    }
};
// @lc code=end

