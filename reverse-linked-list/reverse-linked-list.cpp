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
    ListNode * head1 = NULL;
    
    ListNode* recursiveReverse(ListNode *node) {
        // cout<<"START : "<<node->val<<endl;
        if(node == NULL) {
            return NULL; 
        }
        if(node->next==NULL) {
            // cout<<"HEAD : "<<node->val<<endl;
            // Setting last node as head
            head1 = node; 
            return node;
        }
        
        ListNode* node1 = recursiveReverse(node->next); 
        // cout<<node1->val<<" "<<node->val<<endl;
        
        node1->next = node;
        node->next = NULL;
        
        return node;
    }
    
    ListNode* reverseList(ListNode* head) {    

        recursiveReverse(head);
        return head1;
    }
};