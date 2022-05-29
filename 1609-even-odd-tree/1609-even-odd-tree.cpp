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
    bool isEvenOddTree(TreeNode* root) {
        
        queue<TreeNode*> q; 
        q.push(root);
        int h = 0;
        while(!q.empty()){
            int n = q.size(); 
            int last = 0;
            
            while(n--){
                TreeNode* curr = q.front(); 
                q.pop(); 
                
                if(!last) {
                    if (h%2) {
                        if(!(curr->val%2)) last = curr->val; 
                        else return false; 
                    }else{
                        if((curr->val)%2) last = curr->val; 
                        else return false; 
                    }                
                }
                else{
                    if (h%2) {
                        if(last > curr->val and !(curr->val%2)) last = curr->val; 
                        else return false; 
                    }
                    
                    else {
                        if(last < curr->val and (curr->val)%2) last = curr->val; 
                        else return false; 
                    }
                }
                
                if(curr->left) q.push(curr->left);
                if(curr->right) q.push(curr->right);
            }
            h += 1;
        }
        
        return true;
    }
};