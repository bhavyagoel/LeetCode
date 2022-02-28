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
    ListNode* sortList(ListNode* head) {
        mergeSort(&head);
        return head; 
    }
    
    
private:
    ListNode* merge(ListNode* first, ListNode* second) {
        
        if(!first) return second; 
        if(!second) return first; 
        
        ListNode* temp;
        ListNode* res; 
        
        if(first->val>second->val){
            temp = second; 
            res = second; 
            second = second->next; 
        }else{
            temp = first; 
            res = first; 
            first = first->next; 
        }
        
        
        while(first and second) {
                        
            if(first->val>second->val){
                temp->next = second;
                second = second->next;  
            }else{
                temp->next = first;
                first = first->next; 
            }
            temp = temp->next; 
        }
        
        while(first){
            temp->next = first; 
            first = first->next;
            temp = temp->next; 
        }
        
        while(second) {
            temp->next = second; 
            second = second->next;
            temp = temp->next; 
        }
        
        return res; 
        
        
        /*
        By Recursion
        if(!first) return second; 
        if(!second) return first; 
        
        if(first->val>second->val){
            second->next = merge(first, second->next);
            return second; 
        }else{
            first->next = merge(first->next, second);
            return first; 
        }
        */
        
    }
    
    
    void mergeSort(ListNode** head_ref) {
        ListNode* head = *head_ref; 
        
        if(!head or !head->next) return; 
        
        ListNode* first = head; 
        ListNode* second = head->next; 
        
        while(second and second->next) {
            first = first->next; 
            second = second->next->next; 
        }
        second = first->next;
        first->next = nullptr; 
        first = head; 
        
        mergeSort(&first);
        mergeSort(&second); 
        
        *head_ref = merge(first, second); 
    }
};