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
    ListNode* reverseEvenLengthGroups(ListNode* head, int k = 1) {

        auto node = head; 

        for(int i = 0; i < k-1; ++i) {
            if(!node and i%2==0) return reverse(head); 
            else if(!node) return head; 
            node = node->next; 
        }
        if(!node and k%2) return reverse(head); 
        else if(!node) return head; 
        
        if(k%2==0)  {
            auto next = node->next; 
            node->next = nullptr; 
            auto new_head = reverse(head); 
            head->next = reverseEvenLengthGroups(next, ++k); 
            return new_head;
        }
        node->next = reverseEvenLengthGroups(node->next, ++k); 
        return head; 
        
        
    }
    
    ListNode* reverse(ListNode* head){
        if(!head or !head->next) return head; 
        
        auto res = reverse(head->next);
        head->next->next = head; 
        head->next = nullptr;
        
        return res; 
    }
};