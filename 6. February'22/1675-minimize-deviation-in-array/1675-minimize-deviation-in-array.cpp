class Solution {
public:
    int minimumDeviation(vector<int>& nums) {
        int n = nums.size(); 
        priority_queue<int> max_heap;
        
        int mn = INT_MAX; 
        int mx = INT_MIN; 
        for(int i = 0; i < n; i++) {
            if(nums[i]&1) {
                nums[i] = nums[i]*2; 
            }
            
            max_heap.push(nums[i]); 
            mn = min(mn, nums[i]);
            mx = max(mx, nums[i]);
            
        }
        
        int res = mx - mn; 
        
        while(max_heap.top()%2==0) {
            int top = max_heap.top(); 
            max_heap.pop(); 
            res = min(res, top - mn); 
            
            top /= 2; 
            mn = min(mn, top); 
            max_heap.push(top);
        }
        res = min(res, max_heap.top()-mn);
        return res; 
        
        
        
        
        
        
    }
};