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
        int father[100001] = {0};
        
        TreeNode* res = nullptr; 
        int start = d[0][1];
        
        for(int i = 0; i < d.size(); i++) {
            TreeNode* child = nullptr; 
            TreeNode* parent = nullptr;
            if(!tree[d[i][0]]) {
                parent = new TreeNode(d[i][0]);
                tree[d[i][0]] = parent; 
            }else parent = tree[d[i][0]];
            
            if(!tree[d[i][1]]) {
                child = new TreeNode(d[i][1]);
                tree[d[i][1]] = child; 
            }else child = tree[d[i][1]];
            
            if(d[i][2]) parent->left = child; 
            else parent->right = child; 
            
            father[child->val] = parent->val;
            start = child->val;
            
        }
        
        while(father[start]) start = father[start];
        return tree[start]; 
    }
};

/*
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
*/