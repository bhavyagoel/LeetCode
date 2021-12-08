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
    int totDiff = 0;
    
    int valueSum(TreeNode* root) {
        if(!root) return 0;
        
        int leftSum = valueSum(root->left);
        int rightSum = valueSum(root->right);
        int tilt = abs(leftSum - rightSum);
        
        totDiff += tilt;
        return root->val + leftSum + rightSum;
    }
    
    int findTilt(TreeNode* root) {
        valueSum(root); 
        return totDiff;
    }
};