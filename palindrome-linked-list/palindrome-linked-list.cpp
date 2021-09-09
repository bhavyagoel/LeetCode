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
    
    ListNode* reverse_inplace(ListNode* head_ref) {
        ListNode *prev = NULL;
        ListNode *curr;
        ListNode *next = NULL;
        
        curr = head_ref; 
        
        while(curr) {
            next = curr->next;
            curr->next = prev;
            
            prev = curr; 
            curr = next;
        }
        
        return prev;
    }

    bool isPalindrome(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;
        
        while(fast->next && fast->next->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        
        ListNode *secHalf = reverse_inplace(slow);
        
        
        while(head && secHalf) {
            if(head->val != secHalf->val) {
                return false;
            }
            
            head = head->next; 
            secHalf = secHalf->next; 
        }
        
        return true;
    }
};