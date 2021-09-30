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
    ListNode* merge(ListNode* l1, ListNode* l2) {
        if(l1 == NULL) return l2; 
        if(l2 == NULL) return l1;
        
        if (l1->val > l2->val) {
            l2->next = merge(l1, l2->next);
            return l2; 
        }
        else {
            l1->next = merge(l1->next, l2);
            return l1; 
        }
    }
    
    void FrontBackSplit(ListNode *source, ListNode** backRef, ListNode** frontRef) {
        ListNode *slow_ptr = source;
        ListNode *fast_ptr = source->next;
        
        if (source!=NULL)
        {
            while (fast_ptr != NULL && fast_ptr->next != NULL)
            {
                fast_ptr = fast_ptr->next->next;
                slow_ptr = slow_ptr->next;
            }
        }        
        *frontRef = source;
        *backRef = slow_ptr->next;
        slow_ptr->next = NULL;
    }
    
    void mergeSort(ListNode** head_ref) {
        auto head = *head_ref;
        // cout<<head->val<<endl;
        if(head == NULL || head->next == NULL) return;
        
        ListNode *a;
        ListNode *b;
        
        FrontBackSplit(head, &a, &b);
        
        mergeSort(&a);
        mergeSort(&b);
        
        *head_ref = merge(a, b);
        
    }
};