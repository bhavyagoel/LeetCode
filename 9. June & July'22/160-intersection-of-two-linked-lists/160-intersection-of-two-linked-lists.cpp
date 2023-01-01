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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        
        map<ListNode*, bool> check; 
        while(headA) {
            check[headA] = true; 
            headA = headA->next;
        }
        
        while(headB) {
            if(check[headB]) return headB;
            headB = headB->next;
        }
        
        return nullptr; 
    }
    
    
};