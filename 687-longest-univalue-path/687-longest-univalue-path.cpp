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
    int res = INT_MIN; 
    int helper(TreeNode* root, int val) {
        if(!root) return 0; 
        
        
        int lh = helper(root->left, root->val);
        int rh = helper(root->right, root->val);
        
        res = max(res, lh+rh);
        if(root->val != val) return 0; 
        return 1 + max(lh, rh); 
    }
    
    
    int longestUnivaluePath(TreeNode* root) {
        if(!root) return 0; 
        helper(root, root->val);
        
        return res; 
    }
};