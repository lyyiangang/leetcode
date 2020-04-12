/*
 * @lc app=leetcode.cn id=113 lang=cpp
 *
 * [113] 路径总和 II
 *
 * https://leetcode-cn.com/problems/path-sum-ii/description/
 *
 * algorithms
 * Medium (58.46%)
 * Likes:    200
 * Dislikes: 0
 * Total Accepted:    40.7K
 * Total Submissions: 68.8K
 * Testcase Example:  '[5,4,8,11,null,13,4,7,2,null,null,5,1]\n22'
 *
 * 给定一个二叉树和一个目标和，找到所有从根节点到叶子节点路径总和等于给定目标和的路径。
 * 
 * 说明: 叶子节点是指没有子节点的节点。
 * 
 * 示例:
 * 给定如下二叉树，以及目标和 sum = 22，
 * 
 * ⁠             5
 * ⁠            / \
 * ⁠           4   8
 * ⁠          /   / \
 * ⁠         11  13  4
 * ⁠        /  \    / \
 * ⁠       7    2  5   1
 * 
 * 
 * 返回:
 * 
 * [
 * ⁠  [5,4,11,2],
 * ⁠  [5,8,4,5]
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
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        vector<int> result;
        dfs(root, sum, result);
        // dfs_backtrack(root, sum, result);
        return mResults;
    }

    void dfs(TreeNode* root, int sum, vector<int> result){
        // 常规方法， 每个节点需要存储很长路径， 耗费较多内存
        // Your runtime beats 22.89 % of cpp submissions
        // Your memory usage beats 22.62 % of cpp submissions (36 MB)
        if(root == nullptr)
            return;
        // std::cout<<root->val<<" ";
        result.push_back(root->val);
        if( root->left == nullptr && \
            root-> right == nullptr && \
            std::accumulate(result.begin(), result.end(), 0) == sum){
                mResults.push_back(result);
                return;
            }
        dfs(root->left, sum, result);
        dfs(root->right, sum, result);
    }

    void dfs_backtrack(TreeNode* root, int sum, vector<int>& result){
        // 回溯算法, 遍历完成后会回退到上一个状态. 
        // Your runtime beats 94.36 % of cpp submissions. 
        // Your memory usage beats 100 % of cpp submissions (17 MB)
        if(root == nullptr)
            return;
        result.push_back(root->val);
        if( root->left == nullptr && \
            root-> right == nullptr && \
            std::accumulate(result.begin(), result.end(), 0) == sum)
            {
                mResults.push_back(result);
                result.pop_back();
                return;
            }
        dfs_backtrack(root->left, sum, result);
        dfs_backtrack(root->right, sum, result);
        // 恢复初始状态
        result.pop_back();
    }
private:
    vector<vector<int>> mResults;
};
// @lc code=end

