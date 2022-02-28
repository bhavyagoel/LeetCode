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
    vector<int> rightSideView(TreeNode* root) {
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
};