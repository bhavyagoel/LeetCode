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
    long sum = 0; 
    long res = INT_MIN; 
    int modulo = 1e9 + 7; 
    int maxProduct(TreeNode* root) {
        dfsSum(root); 
        dfs(root); 
        return res%modulo; 
    }
    
    void dfsSum(TreeNode* root) {
        if(!root) return; 
        
        sum += root->val; 
        dfsSum(root->left); 
        dfsSum(root->right); 
        return; 
    }
    
    long dfs(TreeNode* root) {
        if(!root) return 0; 
        
        long left = dfs(root->left); 
        long right = dfs(root->right); 
        
        long s = root->val + left + right;

        long prod = s*(sum-s);
        if(res < prod) res = prod; 

        return s;
    }
};