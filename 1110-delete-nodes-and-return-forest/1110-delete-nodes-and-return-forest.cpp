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
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_del) {
        
        for(auto it : to_del) check[it] = true;
        
        
        dfs(root, true); 
        return res; 
    }
    unordered_map<int, bool> check;
    vector<TreeNode*> res; 
    
    TreeNode* dfs(TreeNode* root, bool isRoot) {
        if(!root) return nullptr; 
        
        bool deleted = check[root->val];
        // isRoot is used to check for childs of deleted nodes as root
        if(isRoot and !deleted) res.push_back(root);
        
        root->left = dfs(root->left, deleted);
        root->right = dfs(root->right, deleted); 
        
        return deleted ? nullptr : root; 
    }
};