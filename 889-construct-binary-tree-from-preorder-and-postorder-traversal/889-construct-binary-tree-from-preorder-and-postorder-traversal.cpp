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
    map<int, int> pos; 
    TreeNode* constructFromPrePost(vector<int>& pre, vector<int>& post) {
        return build(pre, post);
    }
    
    int preInd = 0, postInd = 0; 
    TreeNode* build(vector<int>& pr, vector<int>& po) {
        TreeNode* root = new TreeNode(pr[preInd++]);
        
        if(root->val != po[postInd]) root->left = build(pr, po);
        if(root->val != po[postInd]) root->right = build(pr, po); 
        postInd++; 
        return root; 
    }
};