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
    
    bool helper(TreeNode* root, long mn, long mx) {
        if(!root) return true; 
                
        bool left = helper(root->left, mn, min(mx, (long)root->val));
        bool right = helper(root->right, max(mn, (long)root->val), mx);
        
        
        if(root->val <= mn or root->val >= mx) return false;
        return left and right; 
    }
    
    bool isValidBST(TreeNode* root) {
        return helper(root, LONG_MIN, LONG_MAX);
    }
};