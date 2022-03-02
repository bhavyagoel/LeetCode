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
    map<int, map<int, multiset<int>>> traversal; 
    
    void inorder(TreeNode* root, int lvl, int xAxis) {
        
        if(!root) return; 
        
        traversal[xAxis][lvl].insert(root->val);
        inorder(root->left, lvl+1, xAxis-1);
        inorder(root->right, lvl+1, xAxis+1);
    }
    
    
    
    
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        inorder(root, 0, 0); 
        
        vector<vector<int>> res; 
        for(auto xAxis : traversal) {
            vector<int> temp; 
            for(auto lvl : xAxis.second) {
                for(auto node : lvl.second) {
                    temp.push_back(node);
                }
                
            }
            res.push_back(temp);
        }
        
        return res;
    }
};