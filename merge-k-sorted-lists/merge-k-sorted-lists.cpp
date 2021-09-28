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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int n = lists.size(); 

        ListNode *res = nullptr;
        for(int i = 0 ; i < n; i++) {
            res = mergeSort(lists[i], res);
        }
        
        return res;
    }
    
//     ListNode* mergeKLists(vector<ListNode*>& lists) {
//         int n = lists.size(); 
//         if(n==0) return nullptr;
//         if(n==1) return lists[0];
        
//         for(int i = 0 ; i < n-1; i++) {
//             lists[i+1] = mergeSort(lists[i], lists[i+1]);
//         }
        
//         return lists[n-1];
//     }
    
private:
    ListNode* mergeSort(ListNode* l1, ListNode* l2) {
        if (l1 == NULL) return l2; 
        if (l2 == NULL) return l1;
        
        if(l1->val > l2->val) {
            l2->next = mergeSort(l1, l2->next);
            return l2;
        }
        else{
            l1->next = mergeSort(l1->next, l2);
            return l1; 
        }
    }
};