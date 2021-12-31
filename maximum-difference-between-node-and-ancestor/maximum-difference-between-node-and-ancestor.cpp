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
    int maxAncestorDiff(TreeNode* root, int mn = INT_MAX-1, int mx = 0) {
        if (!root) return mx-mn;
        
        mx = max(mx, root->val);
        mn = min(mn, root->val);
        
        return max(maxAncestorDiff(root->right, mn, mx), maxAncestorDiff(root->left, mn,mx));
    }
};