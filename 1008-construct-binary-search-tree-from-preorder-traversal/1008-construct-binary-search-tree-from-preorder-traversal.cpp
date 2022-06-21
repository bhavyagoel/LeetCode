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
    TreeNode* bstFromPreorder(vector<int>& pre) {
        int i = 0; 
        return build(pre, i, INT_MAX);
    }
    
    TreeNode* build(vector<int>& pre, int& i, int ub) {
        if (i == pre.size() or pre[i]>ub) return nullptr;
        
        TreeNode* root = new TreeNode(pre[i++]);
        root->left = build(pre, i, root->val); 
        root->right = build(pre, i, ub); 
        
        return root; 
    }
};