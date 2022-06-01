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
    int widthOfBinaryTree(TreeNode* root) {

        queue<pair<TreeNode*, unsigned int>> temp; 
        temp.push({root, 1}); 
        unsigned int res = 0; 

        while(!temp.empty()) {
            int curr = temp.size(); 
            
            unsigned int l = temp.front().second, r = l;
            while(curr--){
                TreeNode* check = temp.front().first; 
                r = max(r,temp.front().second); 
                temp.pop(); 
                
                if(check->left){
                    temp.push({check->left, r*2});
                }
                if(check->right) {
                    temp.push({check->right, r*2+1});
                }

            }
            res = max(res, r-l+1); 
        }
        
        return res; 
    }
};