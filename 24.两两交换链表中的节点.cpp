/*
 * @lc app=leetcode.cn id=24 lang=cpp
 *
 * [24] 两两交换链表中的节点
 *
 * https://leetcode-cn.com/problems/swap-nodes-in-pairs/description/
 *
 * algorithms
 * Medium (64.12%)
 * Likes:    414
 * Dislikes: 0
 * Total Accepted:    70.6K
 * Total Submissions: 109.8K
 * Testcase Example:  '[1,2,3,4]'
 *
 * 给定一个链表，两两交换其中相邻的节点，并返回交换后的链表。
 * 
 * 你不能只是单纯的改变节点内部的值，而是需要实际的进行节点交换。
 * 
 * 
 * 
 * 示例:
 * 
 * 给定 1->2->3->4, 你应该返回 2->1->4->3.
 * 
 * 
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        stack<ListNode*> ss;
        ListNode* out_n = nullptr, *out_root = nullptr;
       while(head != nullptr)
       {
          if(ss.size() < 2)
          {
            ss.push(head);
            head = head->next;
          }  
          else
            {
                while(!ss.empty())
                {
                    ListNode* cur_n = ss.top();
                    ss.pop();
                    if(out_n == nullptr)
                    {
                        out_n = cur_n;
                        out_root = out_n;
                    }
                    else
                    {
                        out_n->next = cur_n;
                        out_n = out_n->next;
                    }
                };
            }
       };
    //    cout<<"----"<<endl;
       while(!ss.empty()){
           ListNode* cur_n = ss.top();
           ss.pop();
           if(out_n == nullptr)
            {
                out_n = cur_n;
                out_root = out_n;
            }
            else
            {
                out_n->next = cur_n;
                out_n = out_n->next;
            }
       };
       if(out_n != nullptr)
            out_n->next = nullptr;
       return out_root;
    }
};
// @lc code=end

