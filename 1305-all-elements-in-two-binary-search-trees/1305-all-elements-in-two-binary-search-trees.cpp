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
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        inorder(root1, true);
        inorder(root2, false);
        vector<int> res;
        
        int i = 0; 
        int n = r1.size(); 
        
        int j = 0; 
        int m = r2.size(); 
        while(i<n && j<m) {
            if(r1[i]<r2[j]){
                res.push_back(r1[i++]);
            }
            else {
                res.push_back(r2[j++]);
            }
        }
        
        while(i<n){
            res.push_back(r1[i++]);
        }
        while(j<m){
            res.push_back(r2[j++]);
        }
        
        return res; 
        
    }
    
private:
    vector<int> r1; 
    vector<int> r2; 
    
    void inorder (TreeNode* root, bool root1) {
        if(!root) return; 
    
        inorder(root->left, root1);
        if(root1) r1.push_back(root->val); 
        else r2.push_back(root->val);
        inorder(root->right, root1);
        return;
    }
};