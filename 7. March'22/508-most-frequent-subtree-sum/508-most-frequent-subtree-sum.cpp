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
    map<int, int> freqSum;
    int largestFreq = 0;
    
    int subTreeSum(TreeNode* root) {
        if(!root) return 0;         
        int lSum = subTreeSum(root->left);
        int rSum = subTreeSum(root->right); 
        int sum = root->val+lSum+rSum; 
        freqSum[sum]++;
        largestFreq = max(largestFreq, freqSum[sum]);
        
        return sum;
    }

    vector<int> findFrequentTreeSum(TreeNode* root) {
        subTreeSum(root); 
        vector<int> res; 
        
        for(auto &it : freqSum) {
            if(it.second == largestFreq) res.push_back(it.first);
        }
        
        
        return res;
    }
};