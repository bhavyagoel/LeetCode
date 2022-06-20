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
    bool isCompleteTree(TreeNode* root) {
        
        
        queue<TreeNode*> q; 
        q.push(root); 
        
        int cntCurrLvl = 1; 
        
        while(!q.empty()) {
            int n = q.size(); 
            bool stop = false;
            int check = n; 
            while(n--) {
                TreeNode* curr = q.front(); 
                q.pop(); 
                
                if(check < cntCurrLvl and (curr->left or curr->right)) return false; 
                
                if(curr->left) {
                    if(stop) return false;
                    q.push(curr->left); 
                }
                else stop = true;
                if(curr->right) {
                    if(stop) return false;
                    q.push(curr->right);
                }
                else stop = true; 
            }
            
            cntCurrLvl *= 2;
        }
        
        return true; 
    }
};