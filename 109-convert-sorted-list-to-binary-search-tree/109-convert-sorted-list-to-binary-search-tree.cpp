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
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* sortedListToBST(ListNode* head) {
        return dfs(head, INT_MAX); 
    }
    
    
    TreeNode* dfs(ListNode* head, int ub) {
        if(!head) return nullptr; 
        
        ListNode* fast = head; 
        ListNode* slow = head;
        ListNode* prev = nullptr; 
        
        while(fast->next and fast->next->next) {
            prev = slow; 
            slow = slow->next; 
            fast = fast->next->next; 
        }
        
        ListNode* curr = slow; 
        ListNode* next = slow->next;
        if(prev) prev->next = nullptr;
        
        TreeNode* root = new TreeNode(curr->val); 
        
        if(prev) root->left = dfs(head, root->val);
        else root->left = dfs(prev, root->val); 
        
        root->right = dfs(next, root->val); 
        return root; 
    }
};