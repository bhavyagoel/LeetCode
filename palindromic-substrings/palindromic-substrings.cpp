class Solution {
public:
    int countSubstrings(string s) {
        int n = s.length(); 
        bool dp[n][n]; 
        
        for(int i = 0;i < n; i++) {
            dp[i][i] = true; 
            if(i==n-1) break; 
            dp[i][i+1] = s[i]==s[i+1]; 
        }
        
        
        for(int i = n-3; i >=0; i--) {
            for(int j = n-1; j > i+1; j--) {
                dp[i][j] = (dp[i+1][j-1] && s[i]==s[j]);
            }
        }
        
        int cnt = 0; 
        for(int i = 0; i < n; i++) {
            for(int j = i; j < n; j++) {
                if (dp[i][j]) cnt++;
            }
        }
        
        return cnt;
    }
};