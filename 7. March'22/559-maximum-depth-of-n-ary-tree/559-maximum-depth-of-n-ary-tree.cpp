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
    int res = 0;  
    int maxDepth(Node* root) {
        if(!root) return 0; 
        
        int temp = INT_MIN;
        for(auto it : root->children) {
            temp = max(temp, maxDepth(it));
        }
        
        return 1 + max(res, temp);
    }
};