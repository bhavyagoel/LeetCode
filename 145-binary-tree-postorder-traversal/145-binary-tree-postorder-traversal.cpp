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
    // Morris Traversal
    
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> res; 

        while(root){
            if(!root->right) {
                res.push_back(root->val); 
                root = root->left;
            }
            else {
                // res.push_back(root->val);
                TreeNode* prev = root->right;
                while(prev->left and prev->left != root) prev = prev->left; 
                
                if(!prev->left) {
                    prev->left = root; 
                    res.push_back(root->val); 
                    root = root->right;
                }else{
                    root = root->left; 
                    prev->left = nullptr;
                    
                }
            }
        }
        reverse(res.begin(), res.end()); 
        return res; 
    }
    
};