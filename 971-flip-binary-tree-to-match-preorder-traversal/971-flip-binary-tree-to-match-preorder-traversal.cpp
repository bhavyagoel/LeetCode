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
    vector<int> flipMatchVoyage(TreeNode* root, vector<int>& voyage) {
        dfs(root, voyage);
        return res;
    }
private:
    vector<int> res; 
    int i = 0;
    bool stop = false; // To stop backprop steps
    
    void dfs(TreeNode* root, vector<int>& voy) {
        if(root->val != voy[i]) {
            res = {-1};
            stop = true;
            return;
        }
        
        if(root->left) {
            if (root->left->val != voy[i+1]) {
                if(!root->right) {
                    res = {-1};
                    return;
                }
                if(root->right->val == voy[i+1]){
                    res.push_back(root->val);
                    swap(root->right, root->left);
                }
                else {
                    res = {-1};
                    return;
                }
            }
            
        }else if(root->right and root->right->val != voy[i+1] ){
            res = {-1};
            return;
            
        }
        i += 1;
        if(root->left and !stop) dfs(root->left, voy);
        if(root->right and !stop) dfs(root->right, voy);
        return;
    }
};