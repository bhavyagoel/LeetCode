class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        
        int n = nums.size(); 
        // int sum; 
        int res;
        std::sort(nums.begin(), nums.end());
        int min = INT_MAX; 
        for(int i = 0 ; i < n ; i++) {
            int lo = i+1; 
            int hi = n-1;
            
            while(lo<hi) {
                int sum = nums[i] + nums[lo] + nums[hi];
                
                if(sum > target) {
                    // ans = sum;
                    if(min > (sum-target)) {
                        min = (sum-target);
                        res = sum;
                    }
                    hi--;
                }
                else if(sum < target){
                    
                    if(min > (target - sum)) {
                        min = (target - sum);
                        res = sum;
                    }
                    lo++;
                }
                else {
                    return sum;
                }
            }
        }
        
        return res;
    }
};