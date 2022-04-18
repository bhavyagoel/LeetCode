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
    map<int, int> res; 
    int kthSmallest(TreeNode* root, int k) {
        helper(root);
        
        
        auto it = res.begin(); 
        while(--k){
            ++it; 
        }
        
        return it->first; 
    }
    
    void helper(TreeNode* root){
        if(!root) return; 
        
        res[root->val] = 1;
        helper(root->left);
        helper(root->right);
    }
};