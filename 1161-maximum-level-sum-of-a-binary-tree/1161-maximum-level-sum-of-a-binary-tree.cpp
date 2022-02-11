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
    int maxLevelSum(TreeNode* root) {
        int res = 0; 
        int max_sum = INT_MIN;
        int lvl = 1; 
        
        queue<TreeNode*> temp; 
        temp.push(root);    
        while(!temp.empty()) {
            int curr = temp.size(); 
            int sum = 0; 
            while(curr--) {
                TreeNode* front = temp.front(); 
                temp.pop(); 
                sum += front->val; 
                
                if(front->right) temp.push(front->right);
                if(front->left) temp.push(front->left);
                
            }
            
            if(max_sum < sum) {
                res = lvl; 
                max_sum = sum;
            }
            lvl += 1;
        }
        
        return res; 
    }
};