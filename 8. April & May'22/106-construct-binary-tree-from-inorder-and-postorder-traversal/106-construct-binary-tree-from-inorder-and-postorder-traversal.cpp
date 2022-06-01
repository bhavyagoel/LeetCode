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
    TreeNode* buildTree(vector<int>& in, vector<int>& po) {
        
        int n = in.size(); 
        for(int i = 0; i < n; i++) pos[in[i]] = i;
        
        return buildTree(in, 0, n-1, po, 0, n-1);
    }
    
    TreeNode* buildTree(vector<int>& in, int inSt, int inEn, vector<int>& po, int poSt, int poEn) {
        if(poSt > poEn or inSt > inEn) return nullptr; 
        
        TreeNode* root = new TreeNode(po[poEn]);
        
        int inRoot = pos[po[poEn]];
        int numsLeft = inRoot - inSt; 
        
        root->left = buildTree(in, inSt, inRoot-1, po, poSt, poSt + numsLeft - 1);
        root->right = buildTree(in, inRoot+1, inEn, po, poSt + numsLeft, poEn - 1);
        return root; 
    }
};