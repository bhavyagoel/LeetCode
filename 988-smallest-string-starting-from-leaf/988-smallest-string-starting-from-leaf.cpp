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
    string smallestFromLeaf(TreeNode* root) {
        string temp = "";
        helper(root, temp + char('a'+root->val)); 
        return res; 
        
    }
    
    string res="~"; 
    void helper(TreeNode* root, string temp) {
        if(!root->left and !root->right) {
            reverse(temp.begin(), temp.end()); 
            res = min(res, temp);
        }
                
        if(root->left) {
            char c = 'a' + root->left->val; 
            helper(root->left, temp+c);
        }
        if(root->right) {
            char c = 'a' + root->right->val;
            helper(root->right, temp+c);         
        }
        
    }
};