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
    
    TreeNode* prev;
    TreeNode* first;
    TreeNode* middle; 
    
    void recoverTree(TreeNode* root) {
        dfs(root); 
        int temp = first->val;
        first->val = middle->val; 
        middle->val = temp; 
    }
    
    void dfs(TreeNode* root) {
        if(!root) return; 
        
        dfs(root->left); 
        if(!prev) prev = root; 
        else {
            if(root->val < prev->val){
                if(!first) first = prev; 
                middle = root; 
            }
            prev = root; 
        }
        dfs(root->right);
    }
};