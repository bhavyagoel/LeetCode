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
    int maxDp;
    int deepestLeavesSum(TreeNode* root) {
        int sum = 0; 
        maxDp = maxDepth(root);

        return lowestSum(root, 1);
    }
    
    int lowestSum(TreeNode* root, int depth) {
        if(!root) return 0; 
        if(!root->left && !root-> right && maxDp == depth) return root->val; 

        return lowestSum(root->left, depth+1) + lowestSum(root->right, depth+1);
    }
    
    int maxDepth(TreeNode* root){
        if(!root) return 0; 
        
        return max(1 + maxDepth(root->left), 1 + maxDepth(root->right));
    }
};