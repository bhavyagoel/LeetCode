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
    int res;
    int depth = 0; 
    void inorder(TreeNode* root, int lvl) {
        if(!root) return; 
        
        if(lvl > depth) {
            res = root->val;
            depth = lvl; 
        }
        
        inorder(root->left, lvl+1);
        inorder(root->right, lvl+1);
        return;
    }
    
    
    int findBottomLeftValue(TreeNode* root) {
        res = root->val;
        inorder(root, 0); 
        return res; 
    }
};