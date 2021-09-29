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
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        
        auto head_ref = head; 
        int len = 0; 
        while(head_ref) {
            len++;
            head_ref = head_ref->next;
        }
        
        
        vector<ListNode*> res; 
                
        int first = len%k; 
        int second = k - len%k;
        int size = len/k;
        while(k) {
            ListNode* a = head; 
            ListNode* b = head;
            
            while(first && k) {
                int size_ = size+1;
                auto temp = helper(a, size_);
                res.push_back(temp.first);
                a = temp.second;
                b = temp.second;
                --first;
                --k;
            }
            
            while(second && k) {
                int size_ = size;
                auto temp = helper(b, size_);
                res.push_back(temp.first);
                b = temp.second;
                --second;
                --k;
            }
            
            break;
        }
        
        return res;
    }
    
private:
    pair<ListNode*,ListNode*> helper(ListNode* head, int k) {
        ListNode* a = head?head:nullptr;
        ListNode* b = head?head:nullptr;
        
        if(k==0|| head==nullptr) return make_pair(nullptr, b);
        
        auto temp = helper(head->next, --k);
        a->next = temp.first;
        
        return make_pair(a, temp.second);
        
    }
};