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
    TreeNode* removeLeafNodes(TreeNode* root, int target) {
        dfs(root, target);
        if(root->val == target and !root->left and !root->right) return nullptr;
        return root; 
    }
    /*
    void dfs(TreeNode* root, int t) {
        if (!root) return; 
        
        dfs(root->left, t);
        dfs(root->right, t);
        
        if(root->left and !root->left->left and !root->left->right and root->left->val == t) 
            root->left = nullptr; 
        if(root->right and !root->right->left and !root->right->right and root->right->val == t) 
            root->right = nullptr; 
        
        return;
    }
    */
    TreeNode* dfs(TreeNode* root, int t) {
        if (!root) return nullptr; 
        TreeNode* temp = root; 
        TreeNode* left = dfs(root->left, t);
        TreeNode* right = dfs(root->right, t);
        
        temp->right = right; 
        temp->left = left; 
        
        if(root->val == t and !root->left and !root->right) return nullptr;
        return temp; 
    }
};