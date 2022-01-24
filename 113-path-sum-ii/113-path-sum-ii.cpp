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
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        if(!root) return res;
        vector<int> temp; 
        temp.push_back(root->val);
        recurse(root, temp, targetSum, root->val);
        return res; 
    }
    
private:
    vector<vector<int>> res;
    void recurse(TreeNode* root, vector<int>& temp, int tgt, int sum) {
        if(!root->left and !root->right) {
            if(sum==tgt) {
                res.push_back(temp);
            }
            return; 
        }
        
        if(root->left){
            sum += root->left->val; 
            temp.push_back(root->left->val);
            recurse(root->left, temp, tgt, sum);
            temp.pop_back(); 
            sum -= root->left->val; 
        }
        if(root->right){
            sum += root->right->val; 
            temp.push_back(root->right->val);
            recurse(root->right, temp, tgt, sum);
            temp.pop_back();
            sum -= root->right->val; 
        }
        return;
    }
};