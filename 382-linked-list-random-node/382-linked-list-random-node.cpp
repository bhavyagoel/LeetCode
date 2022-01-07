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
    int length = 0; 
    ListNode* hd; 
    Solution(ListNode* head) {
        ListNode* lenCount = head; 
        while(lenCount) {
            length++; 
            lenCount = lenCount->next; 
        }
        hd = head;
    }
    
    int getRandom() {
        ListNode* temp = hd; 
        int rnd = rand()%length;
        while(rnd) {
            rnd--;
            temp = temp->next; 
        }
        
        return temp->val;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(head);
 * int param_1 = obj->getRandom();
 */