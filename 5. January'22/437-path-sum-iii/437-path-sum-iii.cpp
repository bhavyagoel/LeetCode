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
    int pathSum(TreeNode* root, int targetSum) {
        if(!root) return 0;
        return recurse(root, targetSum, 0) + pathSum(root->left, targetSum) + pathSum(root->right, targetSum);
    }
    
private:
    // int res = 0; 
    int recurse(TreeNode* root, int tgt, int prev) {
        if(!root) return 0;        
        
        int curr = prev + root->val;
        return (curr==tgt) + recurse(root->left, tgt, curr) + recurse(root->right, tgt, curr);
    }
};