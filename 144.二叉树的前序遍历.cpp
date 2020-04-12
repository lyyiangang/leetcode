/*
 * @lc app=leetcode.cn id=144 lang=cpp
 *
 * [144] 二叉树的前序遍历
 *
 * https://leetcode-cn.com/problems/binary-tree-preorder-traversal/description/
 *
 * algorithms
 * Medium (63.94%)
 * Likes:    233
 * Dislikes: 0
 * Total Accepted:    90K
 * Total Submissions: 138.3K
 * Testcase Example:  '[1,null,2,3]'
 *
 * 给定一个二叉树，返回它的 前序 遍历。
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
 * 输出: [1,2,3]
 * 
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
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> result;
        dfs_traverse(root, result);
        // dfs(root, result);
        return result;
    }

    void dfs(TreeNode* root, vector<int>& result){
        if(!root){
            return;
        } 
        result.push_back(root->val);
        dfs(root->left, result);
        dfs(root->right, result); 
    }

    void dfs_traverse(TreeNode* root, vector<int>& result){
        std::stack<TreeNode*> s;
        while(root || !s.empty()){
            if(root){
                result.push_back(root->val);
                s.push(root);
                root = root->left;
            }else{
                root = s.top()->right;
                s.pop();
            }
        }
    }
};
// @lc code=end

