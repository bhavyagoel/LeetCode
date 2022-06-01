class Solution {
public:   
    static bool cmp(const pair<int, int>& a,const pair<int, int>& b) {
        return a.first > b.first;
    }
    
    int largestValsFromLabels(vector<int>& v, vector<int>& l, int numWanted, int useLimit) {
        
        vector<pair<int, int>> pr; 
        int n = v.size(); 
        for(int i = 0; i < n; i++) {
            pr.push_back({v[i], l[i]});
        }
        
        sort(pr.begin(), pr.end(), cmp);
        
        int cnt = 0; 
        
        map<int, int> lbCount;
        int res = 0, i = 0; 
        while(cnt < numWanted and i < n ) {
            if(lbCount[pr[i].second] < useLimit) {
                res += pr[i].first;
                cnt++;
                lbCount[pr[i].second]++;
            }
            i++;
        }
        return res; 
        
        
    }
};