/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* sufficientSubset(TreeNode* root, int limit) {
        return dfs(root, limit); 
    }

    TreeNode* dfs(TreeNode* root, int limit) {
        if(root->left == root->right) {
            return root->val < limit ? nullptr : root;
        }
        
        if(root->left) root->left = dfs(root->left, limit-root->val);
        if(root->right) root->right = dfs(root->right, limit-root->val);
        
        return root->left == root->right ? nullptr : root;
    }
};