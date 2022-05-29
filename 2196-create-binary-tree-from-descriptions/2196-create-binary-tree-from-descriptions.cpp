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
    TreeNode* createBinaryTree(vector<vector<int>>& d) {
        map<int, TreeNode*> tree; 
        map<int, int> parent; 
        TreeNode* res = nullptr; 
        
        for(int i = 0; i < d.size(); i++) {
            TreeNode* temp = nullptr; 
            parent[d[i][1]] = d[i][0];
            
            if(!tree[d[i][0]]) {
                temp = new TreeNode(d[i][0]);
                tree[d[i][0]] = temp; 
            }
            
            if(!tree[d[i][1]]) {
                temp = new TreeNode(d[i][1]);
                tree[d[i][1]] = temp; 
            }
        }
        
        
        for(int i = 0; i < d.size(); i++) {
            TreeNode* child = nullptr; 
            TreeNode* father = nullptr;
            
            father = tree[d[i][0]];
            child = tree[d[i][1]];
            
            if(d[i][2]) father->left = child; 
            else father->right = child; 
            
            if(!res  or !parent[father->val]) {
                // if(res) cout<<parent->val<<" "<<child->val<<" "<<res->val<<endl;
                res = father; 
            }
        }
        return res; 
    }
    
};