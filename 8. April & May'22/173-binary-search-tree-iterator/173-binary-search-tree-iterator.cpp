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
class BSTIterator {
public:
    vector<int> inorder; 
    int i = 0; 
    int size; 
    void helper(TreeNode* root) {
        if(!root) return; 
        
        helper(root->left); 
        inorder.push_back(root->val); 
        helper(root->right); 
        return; 
        
    }
    BSTIterator(TreeNode* root) {
        helper(root); 
        size = inorder.size(); 
    }
    
    int next() {
        return inorder[i++]; 
    }
    
    bool hasNext() {
        return i<size?true:false; 
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */