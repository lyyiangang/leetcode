/*
 * @lc app=leetcode.cn id=19 lang=cpp
 *
 * [19] 删除链表的倒数第N个节点
 *
 * https://leetcode-cn.com/problems/remove-nth-node-from-end-of-list/description/
 *
 * algorithms
 * Medium (37.38%)
 * Likes:    704
 * Dislikes: 0
 * Total Accepted:    127.8K
 * Total Submissions: 338.9K
 * Testcase Example:  '[1,2,3,4,5]\n2'
 *
 * 给定一个链表，删除链表的倒数第 n 个节点，并且返回链表的头结点。
 * 
 * 示例：
 * 
 * 给定一个链表: 1->2->3->4->5, 和 n = 2.
 * 
 * 当删除了倒数第二个节点后，链表变为 1->2->3->5.
 * 
 * 
 * 说明：
 * 
 * 给定的 n 保证是有效的。
 * 
 * 进阶：
 * 
 * 你能尝试使用一趟扫描实现吗？
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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        queue<ListNode*> q_nodes;
        ListNode* root = head;
        while(head != nullptr){
            if(q_nodes.size() >= (n + 1))
                q_nodes.pop();
            q_nodes.push(head);
            head = head->next;
        }
        if(q_nodes.size() == (n + 1)){
            q_nodes.front()->next = q_nodes.front()->next->next;
        }
        else{
            //size == n
            root = q_nodes.front()->next;
        }
        return root;
    }
};
// @lc code=end

