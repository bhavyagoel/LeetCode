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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> res; 
        
        queue<TreeNode*> bfs; 
        
        bfs.push(root);
        
        while(!bfs.empty()){
            
            int currSize = bfs.size(); 
            vector<int> temp; 
            while(currSize--) {
                TreeNode* node = bfs.front(); 
                bfs.pop(); 
                if(!node) break;
                temp.push_back(node->val);
                
                if(node->left){
                    bfs.push(node->left);
                }
                
                if(node->right){
                    bfs.push(node->right);
                }
            }
            
            if(temp.size()) res.push_back(temp);
        }
        reverse(res.begin(), res.end()); 
        return res;
    }
};