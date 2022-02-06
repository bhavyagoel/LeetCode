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
    stack<int> temp;
    vector<int> res;
    vector<int> nextLargerNodes(ListNode* head) {
        // ListNode* alpa = head;
        filler(head); 
        reverse(res.begin(), res.end());
        return res;
        
    }
    
    void filler(ListNode* head) {
        if(!head) return;
        
        filler(head->next);
        while(!temp.empty()) {
            if(temp.top()>head->val) break;
            temp.pop(); 
        }
        int num = temp.empty()?0:temp.top();
        res.push_back(num);
        
        temp.push(head->val);
        return;
    }
};