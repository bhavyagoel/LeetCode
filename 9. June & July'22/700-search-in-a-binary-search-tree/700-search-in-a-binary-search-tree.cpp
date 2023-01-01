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
    TreeNode* searchBST(TreeNode* root, int val) {
        while(root and root->val != val){
            root = root->val > val ? root->left : root->right;
        }
        return root;
    }
    TreeNode* res; 
    void dfs(TreeNode* root, int val) {
        if(!root) return; 
        
        if(root->val == val) {
            res = root; 
            return;
        }
        
        if(root->val > val) dfs(root->left, val);
        else dfs(root->right, val);
        return;
    }
};