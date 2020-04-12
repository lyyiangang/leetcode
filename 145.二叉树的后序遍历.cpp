/*
 * @lc app=leetcode.cn id=145 lang=cpp
 *
 * [145] 二叉树的后序遍历
 *
 * https://leetcode-cn.com/problems/binary-tree-postorder-traversal/description/
 *
 * algorithms
 * Hard (70.01%)
 * Likes:    272
 * Dislikes: 0
 * Total Accepted:    66.7K
 * Total Submissions: 94K
 * Testcase Example:  '[1,null,2,3]'
 *
 * 给定一个二叉树，返回它的 后序 遍历。
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
 * 输出: [3,2,1]
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
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> result; 
        // dfs_postorder(root, result);
        dfs(root, result);
        return result;
    }

   void dfs(TreeNode* root, vector<int>& result){
        if(!root)
            return;
        dfs(root->left, result);
        dfs(root->right, result);
        result.push_back(root->val);
   } 

    void dfs_postorder(TreeNode* root, vector<int>& result){
        std::stack<TreeNode*> s;
        while(root || !s.empty()){
            if(root){
                result.push_back(root->val);
                s.push(root);
                root = root->right;
            }
            else{
                root = s.top()->left;
                s.pop();
            }
        }
        std::reverse(result.begin(), result.end());
    }
};
// @lc code=end

