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
    vector<TreeNode*> res; 
    map<string, vector<TreeNode*>> check;
    
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        dfsSerialise(root); 
        for(auto it : check) {
            if(it.second.size()>1) {
                cout<<it.first<<endl;
                res.push_back(it.second[0]);
            }
        }
        return res; 
    }
    
    
    string dfsSerialise(TreeNode* root) {
        if(!root) return "";
        // brackets are added to define the subtrees uniqueness
        string ser = "(" + dfsSerialise(root->left) + to_string(root->val) + dfsSerialise(root->right) + ")";
        check[ser].push_back(root);
        return ser;
    }
};


/*
class Solution {
public:
    vector<TreeNode*> res; 
    map<string, TreeNode*> check;
    map<string, bool> dupCheck;
    
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        dfs(root); 
        return res; 
    }
    
    void dfs(TreeNode* root) {
        if(!root) return;
        
        string temp = "";
        dfsSerialise(root, temp);
        
        if(check[temp] and !dupCheck[temp]) {
            res.push_back(root);
            dupCheck[temp] = true;
        }
        check[temp] = root;
        dfs(root->left);
        dfs(root->right);
    }
    
    void dfsSerialise(TreeNode* root, string &res) {
        if(!root) {
            res += "null,"; 
            return;
        }
        
        res += to_string(root->val);
        res += ',';
        dfsSerialise(root->left, res);
        dfsSerialise(root->right, res);
        return;
    }
};
*/