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
    int res = 0;
    int multiplier = 1;
    
    int getDecimalValue(ListNode* head) {
        if(!head) return 0;
        
        getDecimalValue(head->next);
        
        int nodeVal = head->val;
        
        res = res + multiplier*nodeVal;
        multiplier = multiplier<<1;
        
        return res;
    }
};