class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        map<int, pair<int, int>> play; 
        
        for(auto it : matches) {
            play[it[0]].first++; 
            play[it[1]].second++;
        }
        
        vector<int> a; 
        vector<int> b; 
        for(auto it : play) {
            if(it.second.second==0) a.push_back(it.first);
            if(it.second.second==1) b.push_back(it.first);
        }
        
        return {a,b}; 
    }
};