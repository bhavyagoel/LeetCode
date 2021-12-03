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
        helper(root, p, q);
        return res; 
    }
    TreeNode* res; 
    
    bool helper(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(!root) return false;
        
        int l = helper(root->left, p, q);
        int r = helper(root->right, p, q);
        int same = (root==p) or (root==q);
        
        if((l+r+same)>=2) res = root;
        
        return (l+r+same)>0;
    }
};