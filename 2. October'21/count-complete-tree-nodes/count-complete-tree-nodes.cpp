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
    int countNodes(TreeNode* root) {
        nodeCount(root);
        return count;
    }
    
private:
    int count = 0;
    void nodeCount(TreeNode* root){
        if(!root) return;
        
        count+=1;
        
        // if(root->right) count+=1;
        // if(root->left) count+=1;
        
        nodeCount(root->right);
        nodeCount(root->left);
    }
};