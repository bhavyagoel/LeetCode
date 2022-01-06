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
    void reorderList(ListNode* head) {
        
        stack<ListNode*> alpha;
        
        ListNode* fast = head->next; 
        ListNode* slow = head;
        
        while(fast and fast->next) {
            fast = fast->next->next;
            slow = slow->next; 
        }
        
        fast = slow->next;
        slow->next = nullptr;
        
        while(fast){
            alpha.push(fast);
            fast = fast->next;
        }
        
        slow = head; 
        fast = slow->next;
        
        while(!alpha.empty()) {
            ListNode* temp = alpha.top(); 
            slow->next = temp; 
            temp->next = fast;
            
            slow = fast;
            if(!slow) break;
            fast = slow->next;
            alpha.pop();
        }
        
    }
};