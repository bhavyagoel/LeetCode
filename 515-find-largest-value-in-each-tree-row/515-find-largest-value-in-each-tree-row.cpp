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
    vector<int> largestValues(TreeNode* root) {
        vector<int> res; 
        if(!root) return {};
        queue<TreeNode*> q; 
        q.push(root); 
        while(!q.empty()) {
            int n = q.size(); 
            int mx = INT_MIN; 
            while(n--) {
                TreeNode* curr = q.front(); 
                q.pop(); 
                
                mx = max(curr->val, mx);
                if(curr->left) q.push(curr->left);
                if(curr->right) q.push(curr->right);
            }
            
            res.push_back(mx);
        }
        return res; 
    }
};