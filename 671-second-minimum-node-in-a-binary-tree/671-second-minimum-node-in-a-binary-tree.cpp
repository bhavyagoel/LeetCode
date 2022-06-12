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
    int findSecondMinimumValue(TreeNode* root) {
        dfs(root);
        return flag?second:-1;
    }
    
    long long first = LLONG_MAX, second = LLONG_MAX;
    bool flag = false;
    
    void dfs(TreeNode* root){
        if(!root) return; 
        
        if(first > root->val)  {
            second = first; 
            first = root->val;
        } 
        else if (root->val < second and root->val != first) {
            second = root->val;
            flag = true;
        }
        
        dfs(root->left);
        dfs(root->right); 
    }
};