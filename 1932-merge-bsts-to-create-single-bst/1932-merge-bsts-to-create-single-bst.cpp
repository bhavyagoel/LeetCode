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
    unordered_map<int, TreeNode*> check; 
    unordered_map<int, int> cnt; 
    
    TreeNode* canMerge(vector<TreeNode*>& t) {        
        for(auto &it : t) {
            check[it->val] = it; 
            ++cnt[it->val];
            ++cnt[it->left ? it->left->val : 0];
            ++cnt[it->right ? it->right->val : 0];
        }
        
        for(auto &it : t){
            if(cnt[it->val]==1) 
                return traverse(it) && check.size()==1 ? it : nullptr; 
        }
        return nullptr; 
    }
    
    bool traverse(TreeNode* r, long ub = LONG_MAX, long lb = LONG_MIN) {
        if(!r) return true; 
        if(r->val <= lb or r->val >= ub) return false; 
        
        if(r->left == r->right) {
            auto it = check.find(r->val);
            if(it != check.end() and it->second != r){
                r->left = it->second->left; 
                r->right = it->second->right; 
                check.erase(it); 
            }
            
        }
        return traverse(r->left, r->val, lb) && traverse(r->right, ub, r->val); 
    }
};