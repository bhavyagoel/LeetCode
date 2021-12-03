class Solution {
public:
    int maxUncrossedLines(vector<int>& nums1, vector<int>& nums2) {
        
        int m = nums1.size(); 
        int n = nums2.size(); 
        int dp[m+1][n+1]; 
        
        dp[0][0] = 0;
        memset(dp, 0, sizeof(dp)); 
        
        for(int i = 1; i <= m; i++) {
            for(int j = 1; j <= n; j++) {
                if (nums1[i-1]==nums2[j-1]) {
                    dp[i][j] = dp[i-1][j-1]+1;
                }else {
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
                }
            }
        }
        
        
        
        return dp[m][n];
    }
};