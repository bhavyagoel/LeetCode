/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        
        map<TreeNode*, TreeNode*> parent; 
        map<TreeNode*, bool> visited; 
        
        queue<TreeNode*> q; 
        q.push(root);
        parent[root] = nullptr;
        
        while(!q.empty()) {
            int n = q.size(); 
            
            while(n--){
                TreeNode* curr = q.front(); 
                q.pop(); 
                
                if(curr->left) {
                    parent[curr->left] = curr;
                    q.push(curr->left);
                }
                
                if(curr->right) {
                    parent[curr->right] = curr; 
                    q.push(curr->right);
                }
            }
        }
        
        
        int dist = 0; 
        
        q.push(target);
        visited[target] = true;
        
        while(!q.empty() and dist != k) {
            int n = q.size(); 
            dist += 1;
            while(n--){
                TreeNode* curr = q.front(); 
                q.pop(); 
                
                if(!visited[parent[curr]] and parent[curr]) {
                    q.push(parent[curr]);
                    visited[parent[curr]] = true; 
                }
                if(!visited[curr->left] and curr->left) {
                    q.push(curr->left);
                    visited[curr->left] = true;
                }
                if(!visited[curr->right] and curr->right) {
                    q.push(curr->right);
                    visited[curr->right] = true;
                }                
            }
        }

        vector<int> res;
        while(!q.empty()) {
            res.push_back(q.front()->val);
            q.pop(); 
        }
        return res;                
    }
};