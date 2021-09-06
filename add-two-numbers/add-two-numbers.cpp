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
    
    void append(ListNode** head_ref, int new_data) {
        ListNode* new_node = new ListNode();
        
        ListNode* last = *head_ref;
        new_node->val = new_data; 
        
        new_node->next = nullptr;
        
        if(*head_ref == NULL) {
            *head_ref = new_node;
            return;
        }
        
        while(last->next != NULL) {
            last = last->next;
        }
        last->next = new_node;
        return;
    }
    
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        
        int add;
        int flag = 0; 
        ListNode* l3 = NULL;
        while(l1 || l2) {
            add = 0;
            
            if(l1 != NULL){
                add += l1->val;
                l1 = l1->next;
            }
            
            if (l2 != NULL) {
                add += l2->val;
                l2 = l2->next;
            }

            
            add+=flag;
            flag = 0;
            
            if(add >=10) {
                add = add%10;
                flag = 1;
            }
            append(&l3, add);
            
            if(l1==NULL && l2==NULL && flag==1){
                append(&l3, flag);
            }
        }
        
        return l3;
    }
};