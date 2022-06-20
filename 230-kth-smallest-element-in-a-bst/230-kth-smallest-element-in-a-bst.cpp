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
        // dfs(root, k); 
        morrisTraversal(root, k);
        return res;
    }
    
    void morrisTraversal(TreeNode* root, int k) {
        
        while(root){
            if(!root->left){
                cnt++;
                if(cnt == k) res = root->val; 
                root = root->right; 
            }else{
                TreeNode* prev = root->left; 
                
                while(prev->right and prev->right != root) prev = prev->right; 
                
                if(!prev->right) {
                    prev->right = root;
                    root = root->left; 
                }else {
                    cnt++;
                    if(cnt == k) res = root->val; 
                    root = root->right; 
                    prev->right = nullptr; 
                }
            }
        }
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