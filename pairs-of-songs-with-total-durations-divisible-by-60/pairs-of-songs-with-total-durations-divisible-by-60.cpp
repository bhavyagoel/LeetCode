class Solution {
public:
    int numPairsDivisibleBy60(vector<int>& time) {
        unordered_map<int, int> temp; 
        int ans = 0; 
        for(auto x : time) {
            ans += temp[(60-x%60)%60];
            temp[x%60]++;
        }
        
        return ans;
    }
};