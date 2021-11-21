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
    ListNode* swapPairs(ListNode* head) {
        if(!head) return nullptr; 
        if(!head->next) return head; 
        
        ListNode* fast=head->next, *slow=head; 
                
        while(fast and slow->next) {
            swap(slow->val, fast->val);
            if(!fast->next) break;
            
            slow=slow->next->next; 
            fast=fast->next->next;
        }
        return head;
    }
};