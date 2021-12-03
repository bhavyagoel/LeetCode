// https://leetcode.com/problems/unique-binary-search-trees/discuss/1565543/C%2B%2BPython-5-Easy-Solutions-w-Explanation-or-Optimization-from-Brute-Force-to-DP-to-Catalan-O(N)

class Solution {
public:
    int dp[21]; 
    int numTrees(int n) {
        if(n<=1) return 1; 
        if(dp[n]) return dp[n];
        int ans = 0; 
        for(int i = 1; i <=n ;i++) {
            dp[n] += numTrees(i-1)*numTrees(n-i);
        }
        return dp[n]; 
    }
};