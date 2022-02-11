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
    bool btreeGameWinningMove(TreeNode* root, int n, int x) {
        if(!root) return false; 
        
        dfs(root, x);
        return max(max(left, right), n-left-right-1) > n/2;

    }
    
private:
    int left, right; 
    int dfs(TreeNode* root, int x) {
        if(!root) return 0; 
        int l = dfs(root->left, x);
        int r = dfs(root->right, x);
        if(root->val == x) {
            left = l; 
            right = r; 
            return 0;
        }
        return 1 + l + r;
    }
};