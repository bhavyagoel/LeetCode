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
    ListNode* insertionSortList(ListNode* head) {
        
        ListNode* dummy = new ListNode(-5006);
        ListNode* curr = head;
        
        while(curr) {
            ListNode* nxt = curr->next; 
            ListNode* iter = dummy; 
            
            while(iter->next and iter->next->val<curr->val){
                iter=iter->next; 
            }
            
            curr->next = iter->next; 
            iter->next = curr; 
            curr = nxt; 
        }
        
        return dummy->next; 

    }
};