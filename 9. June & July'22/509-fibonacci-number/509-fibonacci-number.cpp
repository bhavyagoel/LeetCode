class Solution {
public:
    int fib(int n) {
        return space_optimised(n);
    }
    
    int recursion(int n) {
        if(n<=1) return n; 
        
        return recursion(n-1) + recursion(n-2);
    }
    
    int memoization(int n, vector<int>& dp) {
        if(n<=1) return n; 
        if(dp[n] != -1) return dp[n];
        
        return dp[n] = memoization(n-1, dp) + memoization(n-2, dp);
    }
    
    int tabulation(int n) {
        vector<int> dp(n+1, -1);
        dp[0] = 0;
        dp[1] = 1;
        for(int i = 2; i <= n; i++) {
            dp[i] = dp[i-1] + dp[i-2];
        }
        
        return dp[n];
    }
    
    int space_optimised(int n) {
        if(n<=1) return n;
        int prev2 = 0; 
        int prev = 1; 
        for(int i = 2; i <= n; i++) {
            int curri = prev + prev2;
            prev2 = prev; 
            prev = curri;
        }
        
        return prev;
    }
};