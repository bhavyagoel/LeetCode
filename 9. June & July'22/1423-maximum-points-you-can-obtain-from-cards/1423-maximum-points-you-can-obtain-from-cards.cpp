class Solution {
public:
    int maxScore(vector<int>& c, int k) {
        
        int n = c.size(); 
        int size = n - k; 
        
        int sum = 0;
        
        int totSum = 0; 
        for(auto &it : c) totSum += it;
        
        
        for(int i = 0; i < size; i++) {
            sum += c[i];
        }
        int res = sum;
        int j = 0;
        for(int i = size; i < n; i++) {
            sum -= c[j++];
            sum += c[i];
            res = min(sum, res);
        }
        
        return totSum - res; 
    }
};