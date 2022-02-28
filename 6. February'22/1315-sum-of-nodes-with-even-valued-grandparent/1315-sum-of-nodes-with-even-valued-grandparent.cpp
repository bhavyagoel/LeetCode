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
    int sum_gc(TreeNode* root) {
        int a = 0, b = 0, c = 0, d = 0; 
        
        if(root->left) {
            a = root->left->left ? root->left->left->val : 0; 
            b = root->left->right ? root->left->right->val : 0;
        }
        
        if(root->right) {
            c = root->right->left ? root->right->left->val : 0;
            d = root->right->right ? root->right->right->val : 0;
        }
        
        return a + b + c + d; 
    }
    
    
    int sumEvenGrandparent(TreeNode* root) {
        
        queue<TreeNode*> q; 
        unordered_map<int, bool> checkGP; 
        q.push(root); 
        
        int res = 0;
        while(!q.empty()) {
            int curr = q.size(); 
            while(curr--) {
                TreeNode* temp = q.front(); 
                q.pop(); 
                if(temp->val % 2 == 0) res += sum_gc(temp);
                
                if(temp->right) q.push(temp->right);
                if(temp->left) q.push(temp->left);
                
            }
        }
        
        return res; 
    }
};