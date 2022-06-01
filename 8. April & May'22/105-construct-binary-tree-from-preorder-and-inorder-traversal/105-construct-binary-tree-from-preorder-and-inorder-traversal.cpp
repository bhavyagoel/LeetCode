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
    TreeNode* buildTree(vector<int>& pr, vector<int>& in) {
        
        int n = in.size(); 
        for(int i = 0; i < n; i++) pos[in[i]] = i;
        
        return buildTree(pr, 0, n-1, in, 0, n-1);
    }
    
    TreeNode* buildTree(vector<int>&pr, int prStart, int prEnd, vector<int>&in, int inStart, int inEnd) {
        
        if(prStart > prEnd or inStart > inEnd) return nullptr;
        
        TreeNode* root = new TreeNode(pr[prStart]);
        
        int inRoot = pos[root->val];
        int numsLeft = inRoot - inStart;
        
        root->left = buildTree(pr, prStart + 1, prStart + numsLeft, in, inStart, inRoot -1);
        root->right = buildTree(pr, prStart + numsLeft + 1, prEnd, in, inRoot + 1, inEnd);
        
        return root; 
    }
};