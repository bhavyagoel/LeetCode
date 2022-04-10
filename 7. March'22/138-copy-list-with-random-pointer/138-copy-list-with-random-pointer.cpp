/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        unordered_map<Node*, Node*> copy; 
        
        Node* temp = head; 
        copy[nullptr] = nullptr;
        
        while(temp){
            
            if(!copy[temp]) copy[temp] = new Node(temp->val);
            if(temp->next and !copy[temp->next]) copy[temp->next] = new Node(temp->next->val);
            if(temp->random and !copy[temp->random]) copy[temp->random] = new Node(temp->random->val);
            
            copy[temp]->next = copy[temp->next]; 
            copy[temp]->random = copy[temp->random];
            temp = temp->next; 
        }
        
        return copy[head];
    }
};