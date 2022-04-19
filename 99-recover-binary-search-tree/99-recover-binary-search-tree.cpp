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
    
    TreeNode* pre = new TreeNode(INT_MIN); 
    TreeNode* first = nullptr; 
    TreeNode* sec = nullptr; 
    
    void helper(TreeNode* root) {
        if(!root) return; 
        
        
        helper(root->left);
        
        if( !first and root->val < pre->val) first = pre; 
        if (first and root->val < pre->val) sec = root; 
        
        pre = root; 
        
        helper(root->right); 
    }
    
    void recoverTree(TreeNode* root) {
        helper(root); 
        
        swap(first->val, sec->val);
        

        
    }
};