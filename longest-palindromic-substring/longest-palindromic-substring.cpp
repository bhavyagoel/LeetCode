
// https://leetcode.com/problems/longest-palindromic-substring/discuss/147548/Direct-c%2B%2B-DP

class Solution {
public:
    string longestPalindrome(string s) {
        
        bool dp[s.length()][s.length()];
        dp[0][0] = true;
        int n = s.length(); 
        for(int i = 0 ; i < n; i++) {
            dp[i][i] = true;
        }
        
        for(int i = 0 ; i < n-1; i++) {
            dp[i][i+1] = (s[i]==s[i+1]);
        }
        
        for(int i = n-3; i >= 0; i--) {
            for(int j = n-1; j > i+1; j--) {
                dp[i][j] = dp[i+1][j-1] && (s[i]==s[j]);
            }
        }
        
        string res;
        int max = INT_MIN; 
        for(int i = 0; i < n; i++) {
            for(int j = i; j < n; j++) {
                if(dp[i][j] and j-i+1>max) {
                    res = s.substr(i, j-i+1);
                    max = j-i+1;
                }
            }
        }
        
        return res;
    }
};

/*

// For non-continuous substring 
class Solution {
public:
    string longestPalindrome(string s) {
        string b = s;
        reverse(s.begin(), s.end());
        string dp[s.length()+1][s.length()+1];
        dp[0][0] = "";
        
        for(int i = 1; i <= s.length(); i++) {
            for(int j = 1; j <= s.length(); j++) {
                if(s[i-1] == b[j-1]) {
                    dp[i][j] = dp[i-1][j-1] + s[i-1];
                    if(dp[i-1][j-1].length()==1) {
                        string temp(1,s[i-1]);
                        if (dp[i-1][j-1] ==  temp) {
                            dp[i][j] = s[i-1];
                        }
                    }
                    
                }else{
                    // dp[i][j] = dp[i-1][j].length()>dp[i][j-1].length()?dp[i-1][j]:dp[i][j-1];
                    if(i==j) {
                        string temp = dp[i-1][j].length()>dp[i][j-1].length()?dp[i-1][j]:dp[i][j-1];
                        temp = dp[i-1][j-1].length()>temp.length()?dp[i-1][j-1]:temp;
                        dp[i][j] = temp;
                    }
                    
                }
            }
        }
        
        return dp[s.length()][s.length()];
    }
};


*/