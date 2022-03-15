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
    bool isSymmetric(TreeNode* root) {
        
        if(!root) return true; 
        return check(root->right, root->left);
        
    }
    
    
    bool check(TreeNode* right, TreeNode* left) { 
        if(!right or !left) return left==right; 
        
        if(right->val!= left->val) return false; 
        return check(right->right, left->left) && check(right->left, left->right);
    }
};