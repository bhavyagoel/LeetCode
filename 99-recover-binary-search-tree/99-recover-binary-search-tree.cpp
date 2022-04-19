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
    
    vector<int> inorder;
    
    void helper(TreeNode* root) {
        if(!root) return; 
        
        helper(root->left);
        inorder.push_back(root->val); 
        helper(root->right); 
        return; 
    }    
    
    int i = 0; 
    void helper2(TreeNode* root){
        if(!root) return; 
        
        helper2(root->left); 
        root->val = inorder[i++]; 
        helper2(root->right); 
        return; 
    }
    void recoverTree(TreeNode* root) {
        helper(root);

        sort(inorder.begin(), inorder.end()); 
    
        helper2(root);
        
    }
};