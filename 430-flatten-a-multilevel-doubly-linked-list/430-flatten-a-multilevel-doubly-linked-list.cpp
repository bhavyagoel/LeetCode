/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/

class Solution {
public:
    Node* flatten(Node* head) {
        dfs(head);
        return head; 
    }
    
    Node* prev = nullptr;
    void dfs(Node* head) {
        if(!head) return; 
        
        dfs(head->next); 
        dfs(head->child);
        
        head->next = prev; 
        if(prev) prev->prev = head; 
        head->child = nullptr; 
        prev = head;
    }
};