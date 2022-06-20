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
    int kthSmallest(TreeNode* root, int k) {
        dfs(root, k); 
        return res;
    }
    int res = -1, cnt = 0; 
    void dfs(TreeNode* root, int k) {
        if(!root) return;
        
        dfs(root->left, k); 
        cnt++;
        if(cnt==k) res = root->val; 
        dfs(root->right, k); 
    }
};