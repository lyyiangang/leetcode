/*
 * @lc app=leetcode.cn id=1022 lang=cpp
 *
 * [1022] 从根到叶的二进制数之和
 *
 * https://leetcode-cn.com/problems/sum-of-root-to-leaf-binary-numbers/description/
 *
 * algorithms
 * Easy (56.58%)
 * Likes:    35
 * Dislikes: 0
 * Total Accepted:    4.3K
 * Total Submissions: 7.5K
 * Testcase Example:  '[1,0,1,0,1,0,1]'
 *
 * 给出一棵二叉树，其上每个结点的值都是 0 或 1 。每一条从根到叶的路径都代表一个从最高有效位开始的二进制数。例如，如果路径为 0 -> 1 -> 1
 * -> 0 -> 1，那么它表示二进制数 01101，也就是 13 。
 * 
 * 对树上的每一片叶子，我们都要找出从根到该叶子的路径所表示的数字。
 * 
 * 以 10^9 + 7 为模，返回这些数字之和。
 * 
 * 
 * 
 * 示例：
 * 
 * 
 * 
 * 输入：[1,0,1,0,1,0,1]
 * 输出：22
 * 解释：(100) + (101) + (110) + (111) = 4 + 5 + 6 + 7 = 22
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 树中的结点数介于 1 和 1000 之间。
 * node.val 为 0 或 1 。
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
    int sumRootToLeaf(TreeNode* root) {
        int sum_val = 0; 
        dfs_path(root, {}, sum_val);
//        dfs(root, sum_val, 0);
       return sum_val;
    }
    //methold 1, recursive
    // void dfs(TreeNode* root, int& sum, int parentVal){
    //     if(root == nullptr){
    //         return;
    //     }
    //     parentVal = parentVal << 1 | root->val;
    //     if(root->left == nullptr && root->right == nullptr){
    //         sum += parentVal;
    //         return ;
    //     }
    //     dfs(root->left, sum, parentVal);
    //     dfs(root->right, sum, parentVal);
    // }
    int eval_path(const vector<int>& path){
        int out = 0;
        for(int val : path){
            out = out << 1 | val;
        }
        return out;
    }
    //method 2, recursive with path
    void dfs_path(TreeNode* root, vector<int> cur_path, int& sum){
        if(root == nullptr){
            return;
        }
        cur_path.push_back(root->val);
        if(root->left == nullptr && root->right == nullptr){
            sum += eval_path(cur_path);
            return;
        }
        dfs_path(root->left, cur_path, sum);
        dfs_path(root->right, cur_path, sum);
    }
    // void dfs_iter(TreeNode* root, int& sum){
    //     if(root == nullptr){
    //         return;
    //     }
    //     stack<TreeNode*> ss;
    //     while(root != nullptr || !ss.empty()){
    //         if(root != nullptr){
    //             ss.push(root);
    //             root = root->left;
    //         }
    //         else{
    //             root = ss.top();
    //             ss.pop();
    //             root = root->right;
    //         }
    //     }

    // }
};
// @lc code=end

