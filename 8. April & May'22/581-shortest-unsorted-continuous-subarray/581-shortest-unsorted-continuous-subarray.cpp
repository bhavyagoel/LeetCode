class Solution {
public:
    
    int findUnsortedSubarray(vector<int>& nums) {
        int n = nums.size(); 
        int l = n, r = 0; 
        
        stack<int> temp; 
        
        // Greater element before
        for(int i = 0; i < n; i++) {
            while(!temp.empty() and nums[temp.top()] > nums[i]) {
                l = min(l, temp.top()); 
                temp.pop();
            }
            temp.push(i); 
        }
        
        temp = stack<int>(); 
        // Smaller element ahead
        for(int i = n-1; i > -1; i--) {
            while(!temp.empty() and nums[temp.top()] < nums[i]) {
                r = max(r, temp.top()); 
                temp.pop(); 
            }
            
            temp.push(i);
        }
        return r-l>0?r-l+1:0;
    }
};