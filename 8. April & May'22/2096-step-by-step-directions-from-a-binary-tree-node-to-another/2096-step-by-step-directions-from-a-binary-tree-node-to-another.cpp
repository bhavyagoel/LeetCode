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
    
    string src, dest; 
    void path(TreeNode* root, int s, int d, string& temp) {
        if(!root) return; 
        if(root->val == s) src = temp;
        if(root->val == d) dest = temp;
 
        
        temp.push_back('L');
        path(root->left, s, d, temp); 
        temp.pop_back(); 
        
        temp.push_back('R');
        path(root->right, s, d, temp); 
        temp.pop_back(); 
        
        return;
    }

    
    /*
    bool path(TreeNode* root, int val, string &temp) {
        
        if(root->val == val) return true;
        
        if(root->left and path(root->left, val, temp)) temp.push_back('L');
        else if(root->right and path(root->right, val, temp)) temp.push_back('R');
        return !temp.empty();
        
    }
    */
    string getDirections(TreeNode* root, int s, int d) {
        /*
        path(root, s, src);
        path(root, d, dest);
                
        while(src.size() and dest.size() and src.back()==dest.back()) {
            src.pop_back(); 
            dest.pop_back(); 
        }
                
        return string(src.size(), 'U') + string(rbegin(dest), rend(dest));
        */
        string temp;
        path(root, s, d, temp);
        int i = 0; 
        while(i<src.size() and i<dest.size() and src[i]==dest[i]) i++;
                
        return string(src.size()-i, 'U') + dest.substr(i, dest.size());
    }
};