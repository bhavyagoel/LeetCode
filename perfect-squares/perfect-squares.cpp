class Solution {
public:
    int numSquares(int n) {
        return helper(n);
    }
    
private:
    // int helper(int n) {
    //     int temp = sqrt(n); 
    //     if(temp*temp == n){
    //         return 1;
    //     }
    //     if(n<=3){
    //         return n;
    //     }
    //     int ans = INT_MAX;
    //     for(int i= 1 ; i*i <= n; ++i){
    //         ans = min(ans, 1+helper(n-(i*i)));
    //     }
    //     return ans;
    // }
    
    
    int helper(int n) {
        
        int temp = sqrt(n); 
        if(temp*temp == n){
            return 1;
        }
        if(n<=3){
            return n;
        }
        int dp[n+1]; 
        
        for(int i = 0 ; i <=3; i++) {
            dp[i] = i;
        }
        
        for(int i = 4; i <= n; i++){
            dp[i] = i;
            
            for(int j = 1; j*j <= i; j++){
                dp[i] = min(dp[i], 1+dp[i-j*j]);
            }
            
        }
        
        return dp[n];
    }
};