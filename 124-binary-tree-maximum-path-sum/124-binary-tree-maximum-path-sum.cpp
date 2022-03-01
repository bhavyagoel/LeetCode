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
    
    int helper(TreeNode* root){
        if(!root) return 0; 
        
        int lh = max(0, helper(root->left));
        int rh = max(0, helper(root->right));
        
        res = max(res, root->val+lh+rh);
        
        return root->val + max(lh,rh); 
    }
    
    int maxPathSum(TreeNode* root) {
        helper(root); 
        
        return res; 
    }
};