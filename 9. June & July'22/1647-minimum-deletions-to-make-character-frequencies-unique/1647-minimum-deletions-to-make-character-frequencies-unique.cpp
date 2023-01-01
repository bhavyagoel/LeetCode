class Solution {
public:
    int minDeletions(string s) {
        vector<int> count(26, 0);
        
        for(auto c: s) {
            count[c-'a']++;
        }
        
        sort(count.begin(), count.end(), greater<int>()); 
        
        unordered_map<int, bool> check; 
        
        int res = 0;
        for(int i = 0; i < 26; i++) {
            int cnt = count[i]; 
            if(!check[cnt]) {
                check[cnt] = true; 
                continue;
            }
            
            while(cnt>0 and check[cnt]) {
                cnt--;
                res++;
            }
            check[cnt] = true;
        }
        return res;
    }
};