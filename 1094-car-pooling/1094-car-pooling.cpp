class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        int n = trips.size(); 
        
        map<int, int> passengers; 
        for(int i = 0 ; i < n; i++) {
            passengers[trips[i][1]] += trips[i][0];
            passengers[trips[i][2]] -= trips[i][0];
        }
        
        int cp = 0; 
        for(auto it : passengers) {
            cp += it.second;
            if(cp>capacity) return false;
        }
        
        return true;
    }
};