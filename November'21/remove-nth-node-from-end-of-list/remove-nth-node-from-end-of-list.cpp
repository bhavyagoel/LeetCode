// https://leetcode.com/problems/remove-nth-node-from-end-of-list/discuss/1164537/Short-and-Simple-One-Pass-Solution-w-Explanation-or-Beats-100-or-No-dummy-node-required!


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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* fast = head, *slow = head; 
        while(n--) fast = fast->next; 
        
        if(!fast) return head->next; 
        
        while(fast->next) {
            fast = fast->next; 
            slow = slow->next; 
        }
        
        slow->next = slow->next->next; 
        return head; 
    }
};


/*
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* iter = head; 
        int len = 0; 
        while(iter) {
            len++; 
            iter = iter->next; 
        }
        if(len==n) return head->next; 
        
        int i = 1; 
        for(iter=head; i < len-n; i++) {
            iter = iter->next; 
        }
        
        iter->next = iter->next->next; 
        return head; 
    }
};
*/