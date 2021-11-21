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
    unordered_map<int, int> inmap; 
    TreeNode* buildTree(vector<int>& in, vector<int>& pos) {
        int n = in.size(); 
        for(int i = 0; i < n; i++) {
            inmap[in[i]] = i;
        }
        
        TreeNode* root = helper(in, pos, 0, n-1); 
        return root; 
    }
    
    
    TreeNode* helper(vector<int>& in, vector<int>&pos, int start, int end) {
        
        if(start>end) return NULL;
        
        int root_val = pos.back(); 
        pos.pop_back();
        
        TreeNode* root = new TreeNode(root_val); 
        int idx = inmap[root_val];
        
        root->right = helper(in, pos, idx+1, end);
        root->left = helper(in, pos, start, idx-1);
        
        return root; 
        
    }
};