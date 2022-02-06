class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size(); 
        if(n==1) return nums[0];
        if(n==2) return max(nums[1],nums[0]);
        vector<int> dp(n); 
        
        dp[0] = nums[0]; 
        dp[1] = max(nums[0], nums[1]); 
        
        for(int i = 2; i < n-1; i++) {
            dp[i] = max(nums[i]+dp[i-2], dp[i-1]); 
        }
        
        int res = dp[n-2];
        
        dp[1] = nums[1]; 
        dp[2] = max(nums[1], nums[2]);
        
        for(int i = 3; i < n; i++) {
            dp[i] = max(nums[i]+dp[i-2], dp[i-1]); 
        }
        
        res = max(res, dp[n-1]);
        
        return res;
    }
};