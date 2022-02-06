/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<int> res;
    vector<int> postorder(Node* root) {
        recursive(root);
        return res;
    }
    
private:
    void recursive(Node* root) {
        if(!root) return;
        
        for(auto i : root->children) {
            if(i->children.size() != 0){
                recursive(i);
            }else {
                res.push_back(i->val);
            }
        }
        res.push_back(root->val);
    }
};