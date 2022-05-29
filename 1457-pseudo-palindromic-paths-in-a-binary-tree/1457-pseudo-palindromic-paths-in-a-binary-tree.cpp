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
    int pseudoPalindromicPaths (TreeNode* root) {
        // vector<int> cnt(10, 0);
        // dfs(root, cnt, 1); 
        dfs(root, 0);
        return res; 
    }
    
    int res = 0; 
    /*
    void dfs(TreeNode* root, vector<int> cnt, int depth) {
        if(!root) return;
        cnt[root->val]++;
        
        dfs(root->left, cnt, depth+1);
        dfs(root->right, cnt, depth+1);
        
        // cout<<"\nRoot:"<<root->val<<" "<<depth<<endl;
        if(!root->left and !root->right) {
            bool odd = false; 
            for(int i = 1; i < 10; i++) {
                // cout<<cnt[i]<<" ";
                if(depth%2) {
                    if (cnt[i]%2){
                        if(!odd) odd = true; 
                        else return;
                    }
                }else {
                    if (cnt[i]%2) return;
                }
            }
            res += 1; 
        }
        // cout<<endl;
        return;
    }
    */
    
    void dfs(TreeNode* root, int val) {
        if(!root) return;
        
        val ^= (1 << root->val);
        dfs(root->left, val);
        dfs(root->right, val);
        
        if(!root->left and !root->right) res += (__builtin_popcount(val)<2);
        return;
    }
    
};