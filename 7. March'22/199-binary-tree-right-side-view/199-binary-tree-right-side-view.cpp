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
    vector<int> bfs(TreeNode* root) {
        queue<TreeNode*> temp; 
        vector<int> res; 
        if(!root) return res;
        temp.push(root);
        
        while(!temp.empty()) {
            int curr = temp.size(); 
            while(curr){
                TreeNode* front = temp.front(); 
                temp.pop();
                
                if(curr==1) res.push_back(front->val);
                
                if(front->left) temp.push(front->left);
                if(front->right) temp.push(front->right);
                curr -= 1;
            }
        }
        
        return res;
    }
    
    vector<int> res; 
    map<int, bool> checkLvl; 
    void dfs(TreeNode* root, int lvl) {
        if(!root) return; 
        
        if(!checkLvl[lvl]) {
            res.push_back(root->val); 
            checkLvl[lvl] = true; 
        }
        dfs(root->right, lvl+1); 
        dfs(root->left, lvl+1);
        return;
    }
    
    vector<int> rightSideView(TreeNode* root) {
        dfs(root, 0); 
        return res; 
    }
};