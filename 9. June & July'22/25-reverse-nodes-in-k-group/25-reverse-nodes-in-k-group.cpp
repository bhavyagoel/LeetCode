/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {

        auto node = head; 
        for(int i = 0; i < k-1; ++i){
            if(!node) return head;
            node = node->next; 
        }
        if(!node) return head; 

        auto next = node->next; 
        node->next = nullptr;
        auto new_head = reverse(head);
        head->next = reverseKGroup(next, k); 
        
        return new_head; 
    }
    
    ListNode* reverse(ListNode* head){
        if(!head or !head->next) return head;
        
        ListNode* res = reverse(head->next); 
        head->next->next = head; 
        head->next = nullptr; 
        return res; 
    }
};