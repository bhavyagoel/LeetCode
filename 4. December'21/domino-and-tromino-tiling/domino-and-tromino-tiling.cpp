class Solution {
public:
    long long int modulo = 7 + 1e9;
    int numTilings(int n) {
        
        long long int dp[1000];
        dp[1] = 1; 
        dp[2] = 2; 
        dp[3] = 5;
        
        for(int i = 4; i <=n; i++) {
            dp[i] = ((dp[i-1]*2)%modulo + dp[i-3]%modulo)%modulo;
        }
        
        return dp[n];
    }
    
    int repet(int n) {
        if(n == 1) {
            return 1; 
        }
        if (n==2) {
            return 2; 
        }
        if(n==3) {
            return 5; 
        }
        
        return ((repet(n-1)*2)%modulo + repet(n-3)%modulo)%modulo;
    }
};