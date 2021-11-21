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
    ListNode* swapNodes(ListNode* head, int k) {
        
        ListNode *start=head, *end=head; 
        ListNode*fast=head; 
        while(--k) {
            fast=fast->next; 
            start=start->next; 
        }
        
        while(fast->next){
            end=end->next; 
            fast=fast->next; 
        }
        
        swap(start->val, end->val);
        return head; 
    }
};