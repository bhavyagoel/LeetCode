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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        return helper(l1, l2, 0);
    }
private:
    ListNode* helper(ListNode* l1, ListNode* l2, bool carry) {
        if(!l1 && !l2) {
            auto node = new ListNode(1);
            return carry?node:nullptr;
        }
        
        int val = (l1?l1->val:0) + (l2?l2->val:0) + carry;
        carry = val>=10;
        auto node = new ListNode(val%10);
        
        node-> next = helper(l1?l1->next:nullptr, l2?l2->next:nullptr, carry);
        return node;
    }
};