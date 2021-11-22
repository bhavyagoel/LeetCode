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
    ListNode* rotateRight(ListNode* head, int k) {
        if(!head) return nullptr; 
        if(!head->next) return head; 
        if(k==0) return head; 
        
        int len = 0; 
        ListNode* temp = head; 
        while(temp) {
            temp = temp->next; 
            len++;
        }
        
        k = k%len;
        while(k--) {
            ListNode* fast = head->next;
            ListNode* slow = head;
            while(fast->next) {
                fast = fast->next; 
                slow = slow->next; 
            }
            fast->next = head; 
            slow->next = nullptr; 
            head = fast; 
        }
        
        return head; 
    }
};