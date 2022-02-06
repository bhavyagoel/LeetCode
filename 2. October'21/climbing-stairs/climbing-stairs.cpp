class Solution {
public:
    int climbStairs(int n) {
        int dp[46];
        dp[0] = 1;
        dp[1] = 1;
        // dp[1] = n;
        // int sum = 0;
        for(int i = 2 ; i < n+1; i++) {
            dp[i] = dp[i-1] + dp[i-2];
        }
        return dp[n];
    }
};