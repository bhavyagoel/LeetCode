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
    vector<int> res;
    vector<int> postorderTraversal(TreeNode* root) {
        helper(root);
        return res; 
    }
    
private:
    void helper(TreeNode* root) {
        if(!root) return;
        
        helper(root->left);
        helper(root->right);
        res.push_back(root->val);
    }
};