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
    pair<int, int> temp;
    
    bool isCousins(TreeNode* root, int x, int y) {
        checkDepth(root, x, 0, root->val);
        pair<int, int> alphaX = temp;
        
        checkDepth(root, y, 0, root->val);
        pair<int, int> alphaY = temp;

        return alphaX.first==alphaY.first && alphaX.second != alphaY.second;
        
    }
    
    void checkDepth(TreeNode* root, int x, int depth, int parent){
        if(root == NULL){
            return;
        }
        
        if(root->val == x){
            temp.first = depth; 
            temp.second = parent;
            return;
        }
        
        checkDepth(root->right, x, depth+1, root->val);
        checkDepth(root->left, x, depth+1, root->val);
    }
};

// class Solution {
// public:
//     unordered_map<int, pair<int, int>> temp;
    
//     bool isCousins(TreeNode* root, int x, int y) {
//         checkDepth(root, x, 0, root->val);
//         checkDepth(root, y, 0, root->val);

//         return temp[x].first==temp[y].first && temp[x].second != temp[y].second;
        
//     }
    
//     void checkDepth(TreeNode* root, int x, int depth, int parent){
//         if(root == NULL){
//             return;
//         }
        
//         temp[root->val] = make_pair(depth, parent);
        
//         checkDepth(root->right, x, depth+1, root->val);
//         checkDepth(root->left, x, depth+1, root->val);
//     }
// };