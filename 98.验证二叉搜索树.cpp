/*
 * @lc app=leetcode.cn id=98 lang=cpp
 *
 * [98] 验证二叉搜索树
 *
 * https://leetcode-cn.com/problems/validate-binary-search-tree/description/
 *
 * algorithms
 * Medium (28.78%)
 * Likes:    470
 * Dislikes: 0
 * Total Accepted:    81.6K
 * Total Submissions: 277.1K
 * Testcase Example:  '[2,1,3]'
 *
 * 给定一个二叉树，判断其是否是一个有效的二叉搜索树。
 * 
 * 假设一个二叉搜索树具有如下特征：
 * 
 * 
 * 节点的左子树只包含小于当前节点的数。
 * 节点的右子树只包含大于当前节点的数。
 * 所有左子树和右子树自身必须也是二叉搜索树。
 * 
 * 
 * 示例 1:
 * 
 * 输入:
 * ⁠   2
 * ⁠  / \
 * ⁠ 1   3
 * 输出: true
 * 
 * 
 * 示例 2:
 * 
 * 输入:
 * ⁠   5
 * ⁠  / \
 * ⁠ 1   4
 * / \
 * 3   6
 * 输出: false
 * 解释: 输入为: [5,1,4,null,null,3,6]。
 * 根节点的值为 5 ，但是其右子节点值为 4 。
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
    bool isValidBST(TreeNode* root) {
        // return dfs(root, INT_MIN, INT_MAX);
        return dfs_iter(root);
    }

    bool dfs(TreeNode* root, int min_val, int max_val){
        if(root == nullptr)
            return true;
        if(root->val >= max_val)
            return false;
        if(root->val <= min_val)
            return false;

        if(!dfs(root->left, min_val, root->val))
            return false;
        if(!dfs(root->right, root->val, max_val))
            return false;
        return true;
    }
    bool dfs_iter(TreeNode* root){
        stack<TreeNode*> vec;
        long pre_val = long(INT_MIN) - 1;
        while(root != nullptr || !vec.empty()){
            if(root != nullptr){
                vec.push(root);
                root = root->left;
            }
            else{
                TreeNode* cur_n = vec.top();
                vec.pop(); 
                if(cur_n->val <= pre_val)
                    return false;
                pre_val = cur_n->val;
                root = cur_n->right;
            }
        }
        return true;
    }
};
// @lc code=end

