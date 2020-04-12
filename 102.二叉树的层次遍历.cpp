/*
 * @lc app=leetcode.cn id=102 lang=cpp
 *
 * [102] 二叉树的层次遍历
 *
 * https://leetcode-cn.com/problems/binary-tree-level-order-traversal/description/
 *
 * algorithms
 * Medium (60.68%)
 * Likes:    421
 * Dislikes: 0
 * Total Accepted:    96.5K
 * Total Submissions: 157.4K
 * Testcase Example:  '[3,9,20,null,null,15,7]'
 *
 * 给定一个二叉树，返回其按层次遍历的节点值。 （即逐层地，从左到右访问所有节点）。
 * 
 * 例如:
 * 给定二叉树: [3,9,20,null,null,15,7],
 * 
 * ⁠   3
 * ⁠  / \
 * ⁠ 9  20
 * ⁠   /  \
 * ⁠  15   7
 * 
 * 
 * 返回其层次遍历结果：
 * 
 * [
 * ⁠ [3],
 * ⁠ [9,20],
 * ⁠ [15,7]
 * ]
 * 
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
    vector<vector<int>> levelOrder(TreeNode* root) {
        return iter_level(root);        
    }
    vector<vector<int>> iter_level(TreeNode* root){
        vector<vector<int>> results;
        queue<TreeNode*> q;
        if(root)
            q.push(root);
        while(!q.empty()){
            int size = q.size();
            vector<int> cur_level;
            for(int ii = 0; ii < size; ++ii){
                if(q.front()->left)
                    q.push(q.front()->left);
                if(q.front()->right)
                    q.push(q.front()->right);
                cur_level.push_back(q.front()->val);
                q.pop();
            }
            results.push_back(cur_level);
        }
        return results;
    }
};
// @lc code=end

