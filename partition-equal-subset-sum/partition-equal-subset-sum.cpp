class Solution {
public:
    bool canPartition(vector<int>nums , int target){
        bool dp[nums.size()+1][target+1];
        for(int i =0 ; i < target+1;i++){
            dp[0][i]=false;
        }
        for(int i =0 ; i < nums.size()+1;i++){
            dp[i][0]=true;
        }
        for(int i =1 ; i<= nums.size();i++){
            for(int j = 1 ; j <= target ; j++){
                if(nums[i-1]<=j){
                    dp[i][j] = dp[i-1][j-nums[i-1]] || dp[i-1][j];
                }
                else{
                    dp[i][j]=dp[i-1][j];
                }
                
            }
        }
        return dp[nums.size()][target];
    }
    bool canPartition(vector<int>& nums) {
        int sum =0;
        for(auto it : nums){
            sum+=it;
        }
        if(sum%2!=0){
            return false;
        }
        return canPartition(nums, (sum/2));
    }
};