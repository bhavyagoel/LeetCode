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
    vector<vector<int>> levelOrder(Node* root) {
        
        vector<vector<int>> res; 
        queue<Node*> bfs; 
        
        bfs.push(root);
        
        while(!bfs.empty()) {
            int currSize = bfs.size(); 
            vector<int> temp; 
            while(currSize--) {
                Node* node = bfs.front(); 
                bfs.pop(); 
                if(!node) break;
                temp.push_back(node->val);
                
                for(auto it : node->children) {
                    bfs.push(it);
                }
            }
            
            if(temp.size()) res.push_back(temp);
        }
        
        return res;
    }
    
};