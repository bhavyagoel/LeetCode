class Solution {
public:
    int maxScore(vector<int>& c, int k) {
        
        int n = c.size(); 
        vector<int> prefSum(n+1, 0);
        int totSum = 0;
        
        for(int i = 0 ; i < n; i++) {
            prefSum[i+1] = prefSum[i]+c[i];
            totSum += c[i];
        }
        
        if(n==k) return totSum;
        
        int res = 0;
        int i = 0;
        int rem = n-k;
        while(rem<=n) {
            int diff = totSum - (prefSum[rem]-prefSum[i]);
            res = max(res, diff);
            rem++;
            i++;
        }        
        return res;
    }
};