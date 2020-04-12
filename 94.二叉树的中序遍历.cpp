/*
 * @lc app=leetcode.cn id=94 lang=cpp
 *
 * [94] 二叉树的中序遍历
 *
 * https://leetcode-cn.com/problems/binary-tree-inorder-traversal/description/
 *
 * algorithms
 * Medium (70.00%)
 * Likes:    431
 * Dislikes: 0
 * Total Accepted:    123.7K
 * Total Submissions: 175.1K
 * Testcase Example:  '[1,null,2,3]'
 *
 * 给定一个二叉树，返回它的中序 遍历。
 * 
 * 示例:
 * 
 * 输入: [1,null,2,3]
 * ⁠  1
 * ⁠   \
 * ⁠    2
 * ⁠   /
 * ⁠  3
 * 
 * 输出: [1,3,2]
 * 
 * 进阶: 递归算法很简单，你可以通过迭代算法完成吗？
 * 
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> results;
        Traverse_iter(root, results);
        return results;
    }
    void Traverse_iter(TreeNode* root, vector<int>& results){
        stack<TreeNode*> ss;
        while(!ss.empty() || root != nullptr){
            if(root != nullptr){
                ss.push(root);
                root = root->left;
            }
            else{
                auto cur_n = ss.top();
                results.push_back(cur_n->val);
                ss.pop();
                root = cur_n->right;
            }
        }
    }
    void Traverse(TreeNode* root, vector<int>& results){
        if(root == nullptr)
            return;
        Traverse(root->left, results);
        results.push_back(root->val);
        Traverse(root->right, results);
    }
};
// @lc code=end

