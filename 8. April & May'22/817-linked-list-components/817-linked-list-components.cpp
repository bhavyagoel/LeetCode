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
    int numComponents(ListNode* head, vector<int>& nums) {
        unordered_map<int, int> mp; 
        
        for(auto it : nums) mp[it] = 1;
        
        int res = 0; 
        while(head) {
            if(mp[head->val]==1) {
                while(head and mp[head->val]==1) head = head->next; 
                res++;
            }
            if(head) head = head->next; 
        }
        return res;
    }
};