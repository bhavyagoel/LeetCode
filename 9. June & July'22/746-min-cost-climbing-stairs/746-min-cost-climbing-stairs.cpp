class Solution {
public:
    int minCostClimbingStairs(vector<int>& c) {
        vector<int> dp(c.size()+1, -1);
        return recursion(c.size(), c, dp);
        
    }
    
    int recursion(int n, vector<int>& c, vector<int>& dp){
        if(n<0) return 0;
        if(dp[n]!=-1) return dp[n]; 
        
        int cost = n>=c.size()?0:c[n];
        int left = recursion(n-1, c ,dp) + cost;
        int right = recursion(n-2, c, dp) + cost;
        
        return dp[n] = min(left, right);
    }
    
    
};