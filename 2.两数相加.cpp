/*
 * @lc app=leetcode.cn id=2 lang=cpp
 *
 * [2] 两数相加
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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int left = 0;
        ListNode *root = nullptr;
        ListNode *cur = nullptr;
       while(!(l1 == nullptr && l2 == nullptr ))
       {
           int val1 = l1 == nullptr ? 0 :l1->val;
           int val2 = l2 == nullptr ? 0 : l2->val;
           int out = val1 + val2 + left;
           if(out > 9)
           {
               left = 1;
               out = out % 10; 
           }
           else
           {
               left = 0;
           }
            if(root == nullptr)
            {
                root = new ListNode(out);
                cur = root;
            }
            else
            {
                cur->next = new ListNode(out);
                cur = cur->next;
            }
           if(l1 != nullptr)
                l1 = l1->next;
            if(l2 != nullptr)
                l2 = l2->next;
       };
       if(left > 0)
            cur->next = new ListNode(left);
       return root;
    }
};
// @lc code=end

