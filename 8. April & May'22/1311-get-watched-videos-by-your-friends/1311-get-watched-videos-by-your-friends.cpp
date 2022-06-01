class Solution {
private:
    static bool compare(pair<string,int> &p1, pair<string, int> &p2){
        if (p1.second == p2.second)
            return p1.first < p2.first;
        return p1.second < p2.second;
    }
    
public:
    vector<string> watchedVideosByFriends(vector<vector<string>>& w, vector<vector<int>>& f, int id, int lvl) {
        vector<string> res; 
        
        queue<int> q; 
        unordered_map<int, bool> check;
        
        check[id] = true;
        for(auto it : f[id]) {
            q.push(it);
            check[it] = true;
        }
        
        int level = 1; 
        while(!q.empty()){
            int k = q.size();
            
            if(level == lvl) break;
            while(k--) {
                int here = q.front(); 
                q.pop(); 
                for(auto it : f[here]) {
                    if(!check[it]) {
                        q.push(it);
                        check[it] = true;
                    }
                }
            }
            level += 1;
        }
        
        map<string, int> freq; 
        
        while(!q.empty()){
            int pos = q.front(); 
            for(auto it : w[pos]) freq[it]++;

            q.pop(); 
        }
        
        vector<pair<string, int>> values(freq.begin(), freq.end()); 
        sort(values.begin(), values.end(), compare);
        
        for(auto it : values) res.push_back(it.first);
        
        return res; 
    }
};