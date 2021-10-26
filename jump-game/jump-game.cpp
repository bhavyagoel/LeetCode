class Solution {
public:
    bool canJump(vector<int>& nums) {
        vector<int>dp (100000, 0);
        dp[0] = 1;
        for(int i = 0 ; i < nums.size()-1; i++) {
            if(dp[i] != 0) {
                for(int j = i; j <= i+nums[i]; j++) {
                    dp[j] = 1;
                    if(j == nums.size()-1){
                        return true;
                    }
                }
            }
        }
        
        if(dp[nums.size()-1] == 1){
            return true;
        }
        return false;
    }
};