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
    ListNode* mergeNodes(ListNode* head) {
        ListNode* temp = head; 
        ListNode* front = nullptr; 
        ListNode* origHead = head; 
        
        while(temp) {
            int sum = 0; 
            temp = temp->next; 
            while(temp and temp->val != 0) {
                sum += temp->val; 
                temp = temp->next; 
            }
            if(sum) {
                ListNode* nw = new ListNode(sum);
                if(head->val == 0) {
                    nw->next = head; 
                    front = nw; 
                    head = nw; 
                }else{
                    front->next =  nw; 
                    nw->next = origHead; 
                    front = nw; 
                }
            }
        }
        front->next = nullptr;
        return head; 
    }
};