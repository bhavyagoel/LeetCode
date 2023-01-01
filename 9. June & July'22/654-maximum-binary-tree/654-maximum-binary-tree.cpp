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
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        return dfs(nums, 0, nums.size()-1);;
    }
    
    TreeNode* dfs(vector<int>& nums, int start, int end) {
        if(start > end) return nullptr;         
        int it = max_element(nums.begin()+start, nums.begin()+end+1) - nums.begin();
        
        TreeNode* temp = new TreeNode(nums[it]);
        temp->left = dfs(nums, start, it-1);
        temp->right = dfs(nums, it+1, end);
        
        return temp;
    }
};