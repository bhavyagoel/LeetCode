class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int> pq; 
        k = nums.size() - k + 1; 
        for(int i = 0; i < nums.size(); i++) {
            
            pq.push(nums[i]);
            if(pq.size()>k) pq.pop();
        }
        
        return pq.top(); 
    }
};