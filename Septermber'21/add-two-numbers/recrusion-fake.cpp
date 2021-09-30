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

// #define ll long long int

class Solution {
public:
    ListNode* ans = NULL;
    ListNode* head;
    ListNode* add(ListNode*head1, ListNode*head2, int carry) {
        
        if(head1 == NULL && head2 == NULL) {
            if(carry > 0) {
                ListNode *newNode = new ListNode(carry);
                carry = 0;
                ans->next = newNode;
                ans = ans->next;
            } 
            return head; 
        }
        
        else if (head1 != NULL && head2 != NULL) {
            int sum = head1->val + head2->val + carry;
            carry = 0;
            if(sum > 9) {
                sum -= 10; 
                carry = 1; 
            }
            ListNode *newNode = new ListNode(sum);
            if(ans == NULL) {
                ans = newNode;
                head = ans;
            }else {
                ans->next = newNode; 
                ans = ans->next;
            }
            
            return add(head1->next, head2->next, carry);
        }
        
        else if(head1 != NULL && head2 == NULL) {
            int sum = head1->val + carry;
            carry = 0;
            if(sum > 9) {
                sum -= 10; 
                carry = 1; 
            }
            ListNode *newNode = new ListNode(sum);
            ans->next = newNode; 
            ans = ans->next;
            
            return add(head1->next, head2, carry);
        }
        
         else if(head1 == NULL && head2 != NULL) {
            int sum = head2->val + carry;
            carry = 0;
            if(sum > 9) {
                sum -= 10; 
                carry = 1; 
            }
            ListNode *newNode = new ListNode(sum);
            ans->next = newNode; 
            ans = ans->next;
            
            return add(head1, head2->next, carry);
        }
        return NULL;
        
    }
    
        
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        return add(l1, l2, 0);
        // return head; 
    }
};
