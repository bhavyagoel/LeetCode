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
    int goodNodes(TreeNode* root) {
        dfs(root, INT_MIN); 
        return res; 
    }
    
    int res = 0; 
    
    void dfs(TreeNode* root, int mx) {
        if(!root) return; 
        
        if(mx<=root->val) mx = root->val;
        else res -= 1;

        dfs(root->left, mx);
        dfs(root->right, mx);
        
        res += 1;
        return;
    }
};