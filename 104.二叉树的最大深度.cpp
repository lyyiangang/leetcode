/*
 * @lc app=leetcode.cn id=104 lang=cpp
 *
 * [104] 二叉树的最大深度
 *
 * https://leetcode-cn.com/problems/maximum-depth-of-binary-tree/description/
 *
 * algorithms
 * Easy (72.05%)
 * Likes:    490
 * Dislikes: 0
 * Total Accepted:    147.6K
 * Total Submissions: 203.2K
 * Testcase Example:  '[3,9,20,null,null,15,7]'
 *
 * 给定一个二叉树，找出其最大深度。
 * 
 * 二叉树的深度为根节点到最远叶子节点的最长路径上的节点数。
 * 
 * 说明: 叶子节点是指没有子节点的节点。
 * 
 * 示例：
 * 给定二叉树 [3,9,20,null,null,15,7]，
 * 
 * ⁠   3
 * ⁠  / \
 * ⁠ 9  20
 * ⁠   /  \
 * ⁠  15   7
 * 
 * 返回它的最大深度 3 。
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
 #include <map>

class Solution {
public:
    int maxDepth(TreeNode* root) {
        return max_depth_iter(root);
        // if(root == nullptr)
        //     return 0;
        // return max(maxDepth(root->left), maxDepth(root->right)) + 1;
    }
    int max_depth_iter(TreeNode* root){
        queue<std::pair<TreeNode*, int>> q;
        int max_depth = 0;
        if(root){
            q.push({root, 1});
        }
        while(!q.empty()){
            TreeNode* node = q.front().first;
            int cur_depth = q.front().second;
            q.pop();
            max_depth = cur_depth;
            // max_depth = max(max_depth, cur_depth); 
            if(node->left){
                q.push({node->left, cur_depth + 1});
            }
            if(node->right){
                q.push({node->right, cur_depth + 1});
            }
        }
        return max_depth;
    }
};
// @lc code=end

