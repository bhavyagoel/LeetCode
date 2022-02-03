class Solution {
public:
    int fourSumCount(vector<int>& a, vector<int>& b, vector<int>& c, vector<int>& d) {
        int n = a.size(); 
        
        unordered_map<int, int> count; 
        
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                count[a[i]+b[j]]++;
            }
        }
        int res = 0; 
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                int check = -(c[i]+d[j]);
                res += count[check];
            }
        }
        return res; 
    }
};