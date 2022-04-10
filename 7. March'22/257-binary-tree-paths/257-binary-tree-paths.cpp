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
    vector<string> binaryTreePaths(TreeNode* root) {
        
        helper(root, to_string(root->val));
        return res; 
    }
    
    vector<string> res;
    
    void helper(TreeNode* root, string temp="") {
        if(!root->left and !root->right) {
            res.push_back(temp);
            return; 
        }
        
        
        if(root->left) helper(root->left, temp+"->"+to_string(root->left->val));
        if(root->right) helper(root->right, temp+"->"+to_string(root->right->val)); 
        return;
    }
};