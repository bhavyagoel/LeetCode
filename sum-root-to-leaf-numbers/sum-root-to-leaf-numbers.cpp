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
    int sumNumbers(TreeNode* root) {
        int res = recursive(root, 0);
        
        return res;
    }
    
    int recursive(TreeNode*root, int num){
        
        if(!root) {
            return 0;
        } 
        num = num*10 + root->val;
        if(!root ->left and !root->right){
            return num;
        }
        
        int left = 0; 
        int right = 0; 
        if(root->left) left = recursive(root->left, num); 
        if(root->right) right = recursive(root->right, num);
        return left + right;
    }
};