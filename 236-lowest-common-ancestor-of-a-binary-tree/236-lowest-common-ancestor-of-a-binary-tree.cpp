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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(!root) return nullptr; 
        if(root==p) return root;
        if(root==q) return root; 
        
        
        
        TreeNode* lft = lowestCommonAncestor(root->left, p, q);
        TreeNode* rgt = lowestCommonAncestor(root->right, p, q);
        
        if(!lft and !rgt) return nullptr; 
        if(!lft and rgt) return rgt; 
        if(lft and !rgt) return lft;
        return root; 
    }
};