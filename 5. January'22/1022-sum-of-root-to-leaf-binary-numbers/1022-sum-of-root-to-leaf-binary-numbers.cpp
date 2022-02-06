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
    int sumRootToLeaf(TreeNode* root, int val = 0) {
        if (!root) return 0;
        val = (val * 2 + root->val);
        return root->left == root->right ? val : sumRootToLeaf(root->left, val) + sumRootToLeaf(root->right, val);
    }
    
//     int totSum = 0; 
//     void helper(TreeNode* root, int val = 0) {
//         if(!root) return;
//         if(!root->left and !root->right) {
//             val = val<<1;
//             val = val | root->val; 
//             totSum += val;
//             return; 
//         }
        
//         val = val<<1;
//         val = val | root->val; 
        
//         helper(root->left, val);
//         helper(root->right, val);        
        
//     }
//     int sumRootToLeaf(TreeNode* root) {
//         helper(root);
//         return totSum;
                
//     }
};


