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
        
        if(!head1 && !head2 && !carry) {
            return NULL;
        }
        
        int cur_sum = (head1 ? head1->val : 0) + (head2 ? head2->val : 0) + carry;
        ListNode* curNode = new ListNode(cur_sum%10);
        carry = cur_sum/10;
        curNode->next = add(head1 ? head1->next : NULL, head2 ? head2->next : NULL, carry);
        return curNode;
    }
    
        
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        return add(l1, l2, 0);
        // return head; 
    }
};
