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
    int sumOfLeftLeaves(TreeNode* root) {
        return helper(root, false);
    }
    
    int helper(TreeNode* root, bool lft) {
        if(!root) return 0; 
        if(!root->left && !root->right && lft) return root->val;
        
        return helper(root->right, false) + helper(root->left, true);
    }
};


/*
class Solution {
public:
    int sumOfLeftLeaves(TreeNode* root) {
        
        int sum = 0; 
        if(!root) return 0; 
        if(!root->left) return 0;
        
        if(root->left && !root->left->left && !root->left->right) sum += root->left->val;
        
        sumOfLeftLeaves(root->left);
        sumOfLeftLeaves(root->right);
        
        return sum;
    }
};
*/