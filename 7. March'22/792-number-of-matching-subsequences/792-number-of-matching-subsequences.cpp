class Solution {
public:
    
    // Checking index of s present at
    int numMatchingSubseq(string s, vector<string>& words) {
        vector<int> pos[26]; 
        int n = s.size(); 
        int res = 0; 
        for(int i = 0; i < n; i++) {
            pos[s[i]-'a'].push_back(i);
        }
        
        for(auto &word : words) {
            int x = -1; 
            bool found = true; 
            
            for(auto &ch : word) {
                auto it = upper_bound(pos[ch-'a'].begin(), pos[ch-'a'].end(), x);
                if(it == pos[ch-'a'].end()) found = false; 
                else x = *it; 
            }
            
            if(found) res++;
        }
        
        return res; 
        
        
        
    }
    
    
    // TLE 
    /*
    int numMatchingSubseq(string s, vector<string>& words) {
        int n = words.size(); 
        // int pos[n] = {0};
        vector<int> pos(n, 0);

        for(auto &it : s) {
            
            for(int i = 0; i < n; i++) {
                if(pos[i] == words[i].size()) continue;
                if(it == words[i][pos[i]]) pos[i]++; 
            }
        }
        
        int res = 0; 
        for(int i = 0; i < n; i++) {
            if(words[i].size()==pos[i]) res++;
        }
        
        return res; 
    }
    */
    
    
    // Checking for words with their waiting characters
    /*
    int numMatchingSubseq(string s, vector<string>& words) {
        int n = words.size(); 
        vector<const char*> word[128];
        
        for(auto &it : words) {
            word[it[0]].push_back(it.c_str());
        }
        
        for(char &ch : s) {
            auto advance = word[ch];
            word[ch].clear();
            for(auto &it : advance) {
                word[*++it].push_back(it);
            }
        }
        
        return word[0].size(); 
    }
    */
};