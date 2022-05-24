class TopVotedCandidate {
public:
    map<int, int> votes; 
    vector<pair<int, int>> winner; 
    int currWinner = -1; 
    
    TopVotedCandidate(vector<int>& p, vector<int>& t) {
        int n = p.size(); 
        for(int i = 0; i < n; i++) {
            votes[p[i]]++;
            if(votes[p[i]] >= votes[currWinner]) currWinner = p[i];
            winner.push_back({t[i], currWinner});
        }
    }
    
    int q(int t) {
        int hi = winner.size(), lo = 0; 
        
        while(lo < hi) {
            int mid = (hi + lo)/2;
            if(t < winner[mid].first) hi = mid;  
            else {
                lo = mid+1; 
            }
        }
        if(hi>=winner.size()) hi = winner.size()-1; 
        if(winner[hi].first > t) hi>0?hi--:0;
        return winner[hi].second; 
    }
};

/**
 * Your TopVotedCandidate object will be instantiated and called as such:
 * TopVotedCandidate* obj = new TopVotedCandidate(persons, times);
 * int param_1 = obj->q(t);
 */