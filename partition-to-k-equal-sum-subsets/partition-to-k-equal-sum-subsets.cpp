// https://leetcode.com/problems/partition-to-k-equal-sum-subsets/discuss/480707/C%2B%2B-DP-bit-manipulation-in-20-lines

class Solution {
public:
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        
        int n = size(nums); 
        int sum = 0;
        int largest = INT_MIN; 
        for(int i = 0; i < n; i++) {
            sum += nums[i]; 
            largest = max(largest, nums[i]);
        }
        
        if(sum%k) return false; 
        
        int target = sum/k;
        if(target < largest) return false; 
        
        int dp[(1<<n)+1];
        memset(dp, -1, sizeof(dp));
        dp[0] = 0;
        
        for(int mask = 0; mask < (1<<n); mask++) {
            if (dp[mask] == -1) continue;
            
            for(int j = 0 ; j < n; j++) {
                if(!(mask&(1<<j)) and (dp[mask]+nums[j] <= target)) {
                    dp[mask | (1<<j)] = (dp[mask] + nums[j])%target;
                }
            }
        }
        return dp[(1<<n)-1] == 0;
    }    
};