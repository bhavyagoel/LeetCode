class Solution {
public:
    int findJudge(int N, vector<vector<int>>& trust) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        unordered_map<int, int> hash;
        for(int i=1; i<=N; i++) hash[i] = 0;
        for(auto &v : trust){
            auto it = hash.find(v[1]);
            if(it != hash.end()) it->second++;
            hash.erase(v[0]);
        }
        for(auto &e : hash)
            if(e.second == N-1) return e.first;
        
        return -1;
    }
};
