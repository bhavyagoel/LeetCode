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
    int averageOfSubtree(TreeNode* root) {
        dfs(root); 
        return res; 
    }
    
    int res = 0; 
    pair<int, int> dfs(TreeNode* root) {
        if (!root) return {0, 0};
        
        pair<int, int> left = dfs(root->left);
        pair<int, int> right = dfs(root->right);
        
        int cnt = left.second + right.second + 1; 
        int sum = left.first + right.first + root->val;
        
        // cout<<sum<<" "<<cnt<<endl;
        
        if(root->val == sum/cnt) res += 1; 
        return {sum, cnt};
    }
};