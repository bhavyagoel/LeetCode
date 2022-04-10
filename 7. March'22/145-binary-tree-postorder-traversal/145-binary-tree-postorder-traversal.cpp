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
    vector<int> postorderTraversal(TreeNode* root) {
        if(!root) return {};
        stack<pair<TreeNode*, int>> tmp; 
        vector<int> pre; 
        vector<int> post; 
        vector<int> in; 
        
        tmp.push({root, 1});
        while(!tmp.empty()) {
            
            TreeNode* top = tmp.top().first; 
            int num = tmp.top().second; 
            
            if(num==1){
                pre.push_back(top->val);
                tmp.top().second += 1; 
                if(top->left) tmp.push({top->left, 1});
            }
            else if (num==2) {
                in.push_back(top->val);
                tmp.top().second += 1; 
                if(top->right) tmp.push({top->right, 1});
            }
            else{
                post.push_back(top->val); 
                tmp.pop();
            }
        }
        
        return post;
    }
};