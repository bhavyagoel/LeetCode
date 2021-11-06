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

    int find_it(TreeNode* root)

{

    if(!root) return INT_MAX-100;

    if(!root->left and !root->right) return 1;

    return 1 + min( find_it(root->left) , find_it(root->right));

}

int minDepth(TreeNode* root) {



    if(!root) return 0;

    return find_it(root);

}

    

};
