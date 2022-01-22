class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size(); 
        list<int> decOrder;
        vector<int> res;
        
        for(int i = 0; i < n; i++) {
            
            while(decOrder.size() and nums[decOrder.back()]<nums[i]) {
                decOrder.pop_back(); 
            }
            
            while(decOrder.size() and decOrder.front()<=i-k){
                decOrder.pop_front(); 
            }
            decOrder.push_back(i);
            if(i>=k-1) res.push_back(nums[decOrder.front()]);
            
        }
        
        return res;
    }
};