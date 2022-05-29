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
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        
        if(depth == 1) {
            TreeNode* temp = new TreeNode(val);
            temp->left = root; 
            return temp; 
        }
        dfs(root, val, depth, 1); 
        return root; 
    }
    
    void dfs(TreeNode* root, int val, int depth, int currDepth) {
        if(!root) return; 
        
        if (depth == currDepth + 1) {
            if(root->left){
                TreeNode* temp = root->left; 
                root->left = new TreeNode(val);
                root->left->left = temp; 
            }else{
                root->left = new TreeNode(val);
            }
            
            if(root->right){
                TreeNode* temp = root->right; 
                root->right = new TreeNode(val);
                root->right->right = temp; 
            }else{
                root->right = new TreeNode(val);
            }
        }
        
        dfs(root->left, val, depth, currDepth+1);
        dfs(root->right, val, depth, currDepth+1);
        return;
    }
};