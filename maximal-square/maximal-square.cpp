class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int r= matrix.size();
        int c= matrix[0].size();
        int ans=0;
        vector<vector<int>> dp(r,vector<int>(c,0));
        for(int i=dp.size()-1;i>=0;i--)
        {
            for(int j=dp[0].size()-1;j>=0;j--)
            {
                if(i==dp.size()-1)
                {
                    dp[i][j]= matrix[i][j]-'0';
                }
                else if(j==dp[0].size()-1)
                {
                    dp[i][j]= matrix[i][j]-'0';
                }
                else if(i==dp.size()-1&&j==dp[0].size()-1)
                {
                    dp[i][j]= matrix[i][j]-'0';
                }
                else
                {
                    if(matrix[i][j]=='1')
                    {
                        int mi= min(dp[i][j+1],dp[i+1][j]);   //here we check the minimum of right and the bottom element
                        int m= min(mi,dp[i+1][j+1]);   // then we compare this minimum with the diagonal element and compute the overall minimum
                        dp[i][j]= m+1;   
                    }
                }
                if(dp[i][j]>ans)
                    ans= dp[i][j]; 
             }
         }
           return ans*ans;
      }
};
