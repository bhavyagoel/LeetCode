class Solution {
public:
    int n ;
    bool fun(vector<int> &nums , int ind , vector<int> &dp)
    {
        if(ind >= n-1)  return true ;
        if(dp[ind] != -1)  return dp[ind] ;
        
        for(int jump=1 ; jump <= nums[ind] && (ind+jump < n) ; jump++)  
        {
            if(fun(nums , ind+jump , dp)) 
            {
                dp[ind]=1 ;
                return true ;
            }
        }
        return dp[ind] = 0 ;
    }
    bool canJump(vector<int>& nums) {
        n=nums.size() ;
        vector<int> dp(n+1 , -1) ;
        return fun(nums , 0 , dp) ;
    }
};
