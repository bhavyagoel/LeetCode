/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    unordered_map<Node*, Node*> copy; 
    
    Node* cloneGraph(Node* node) {
        if(!node) return nullptr;
        
        queue<Node*> bfs; 
        bfs.push(node);
                    
        while(!bfs.empty()) {
            int curr = bfs.size(); 
            
            while(curr--){
                Node* here = bfs.front(); 
                bfs.pop(); 
                
                if(!copy[here]) copy[here] = new Node(here->val); 
                
                for(auto it : here->neighbors) {
                    if(!copy[it]) {
                        copy[it] = new Node(it->val);
                        bfs.push(it);
                    }
                    
                    copy[here]->neighbors.push_back(copy[it]);                        
                }
                    
            }
        }
        
        return copy[node]; 
    }
    
};