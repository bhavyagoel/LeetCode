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
    TreeNode* buildTree(vector<int>& pre, vector<int>& in) {
        int n = in.size(); 
        for(int i =0 ; i < n; i++) {
            inmap[in[i]] = i; 
        }
        
        return helper(pre, in, 0, n-1); 
    }
    int preIdx = 0; 
    TreeNode* helper(vector<int>& pre, vector<int>& in, int start, int end) {
        if(start>end) return NULL; 
        
        int root_val = pre[preIdx];
        preIdx++;
        
        TreeNode* root = new TreeNode(root_val); 
        int idx = inmap[root_val];
        root->left = helper(pre, in, start, idx-1); 
        root->right = helper(pre, in, idx+1, end);
        
        return root; 
    }
};