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
    int rows = 0, cols = 0; 
    vector<vector<string>> printTree(TreeNode* root) {
        
        queue<TreeNode*>q; 
        q.push(root);
        while(!q.empty()){
            int n = q.size();             
            while(n--){
                TreeNode* curr = q.front(); 
                q.pop(); 
                
                if(curr->left) q.push(curr->left);
                if(curr->right) q.push(curr->right); 
            }
            
            rows += 1; 
        }
        cols = pow(2, rows) - 1;
        
        vector<vector<string>>res(rows, vector<string>(cols, ""));
        dfs(res, root, 0, (cols-1)/2);
        return res;
    }
    
    
    void dfs(vector<vector<string>>& res, TreeNode* root, int m, int n) {
        if(!root) return; 

        dfs(res, root->left, m+1, n-pow(2, rows-1)/pow(2, m+1));
        dfs(res, root->right, m+1, n+pow(2, rows-1)/pow(2, m+1));
        
        res[m][n] = to_string(root->val);
        return;
        
    }
};