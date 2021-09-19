/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        
        unordered_map<ListNode*, ListNode*> node; 

        while(head) {
            if(node[head] == head) {
                return head;
            } 
            
            node[head] = head;
            head = head->next; 
        }
        
        return NULL;
    }
};