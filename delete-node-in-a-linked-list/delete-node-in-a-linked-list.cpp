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
    void deleteNode(ListNode* node) {
        int val = node->val; 
        auto node_ref = node;
        
        while(node->next) {
            node->val = node->next->val;
            node = node->next;
        }
        
        while(node_ref){
            if (node_ref->next->next == nullptr) {
                node_ref->next = nullptr;
                break;
            }
            node_ref = node_ref->next;
        }
    }
};