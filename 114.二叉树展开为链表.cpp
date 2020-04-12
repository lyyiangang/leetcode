/*
 * @lc app=leetcode.cn id=114 lang=cpp
 *
 * [114] 二叉树展开为链表
 *
 * https://leetcode-cn.com/problems/flatten-binary-tree-to-linked-list/description/
 *
 * algorithms
 * Medium (67.31%)
 * Likes:    312
 * Dislikes: 0
 * Total Accepted:    35.3K
 * Total Submissions: 51.6K
 * Testcase Example:  '[1,2,5,3,4,null,6]'
 *
 * 给定一个二叉树，原地将它展开为链表。
 * 
 * 例如，给定二叉树
 * 
 * ⁠   1
 * ⁠  / \
 * ⁠ 2   5
 * ⁠/ \   \
 * 3   4   6
 * 
 * 将其展开为：
 * 
 * 1
 * ⁠\
 * ⁠ 2
 * ⁠  \
 * ⁠   3
 * ⁠    \
 * ⁠     4
 * ⁠      \
 * ⁠       5
 * ⁠        \
 * ⁠         6
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
    void flatten(TreeNode* root) {
        if(root == nullptr)
            return;
        std::vector<TreeNode*> preorders;
        dfs(root, preorders);
        for(int ii = 0; ii < preorders.size() - 1; ++ ii){
            preorders[ii]->left = nullptr;
            preorders[ii]->right = preorders[ii + 1];
        }
    }

    void dfs(TreeNode* root, std::vector<TreeNode*>& preorder){
        if(root == nullptr)
            return;
        preorder.push_back(root);
        dfs(root->left, preorder);
        dfs(root->right, preorder);
    }
};
// @lc code=end

