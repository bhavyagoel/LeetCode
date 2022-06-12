/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        dfs(root);
        dfs(root);
        dfs(root);
        dfs(root);
        dfs(root);
        dfs(root);
        dfs(root);
        dfs(root);
        dfs(root);
        dfs(root);
        dfs(root);
        return root;
    }
    
    void dfs(Node* root) {
        if(!root) return;
        
        if(root->left) {
            if(root->right) root->left->next = root->right;
            else{
                Node* temp = root->next;
                while(temp) {
                    if(temp->left) {
                        root->left->next = temp->left;
                        break;
                    }
                    else if(temp->right) {
                        root->left->next = temp->right;
                        break;
                    }
                    temp = temp->next;
                }
            }
        }
        
        if(root->right){
            Node* temp = root->next;
            while(temp) {
                if(temp->left) {
                    root->right->next = temp->left;
                    break;
                }
                else if(temp->right) {
                    root->right->next = temp->right;
                    break;
                }
                temp = temp->next;
            }
        }
        
        dfs(root->left);
        dfs(root->right);
    }
};