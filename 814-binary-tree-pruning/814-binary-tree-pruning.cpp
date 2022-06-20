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
    TreeNode* pruneTree(TreeNode* root) {
        return dfs(root);
    }
    
    TreeNode* dfs(TreeNode* root) {
        if(!root) return nullptr; 
        
        root->left = dfs(root->left);
        root->right = dfs(root->right);
        
        if(root->val == 1) return root;
        return root->left == root->right ? nullptr : root;
    }
};