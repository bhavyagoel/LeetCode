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
        recurse(root, temp, targetSum, 0);
        return res; 
    }
    
private:
    vector<vector<int>> res;
    void recurse(TreeNode* root, vector<int>& temp, int tgt, int sum) {
        if(!root) {
            return; 
        }
        
        sum += root->val; 
        temp.push_back(root->val);
        
        if(!root->left and !root->right and sum==tgt) {
            res.push_back(temp);
        }else {
            recurse(root->left, temp, tgt, sum);
            recurse(root->right, temp, tgt, sum);
        }
        
        temp.pop_back(); 
        sum -= root->val; 
        return;
    }
};