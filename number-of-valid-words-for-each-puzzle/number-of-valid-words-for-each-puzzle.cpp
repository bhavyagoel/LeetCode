class Solution {
public:
    int getMask(string word) {
        int res = 0; 
        for(auto &i : word) res |= (1<<(i-'a'));
        
        return res; 
    } 
    
    
    vector<int> findNumOfValidWords(vector<string>& words, vector<string>& puzzles) {
        
        unordered_map<int, int> freq;
        
        for (auto &word: words) {
            int mask = getMask(word); 
            freq[mask]++;
        }
        
        vector<int> res; 
        for(auto &p : puzzles) {
            int mask = getMask(p);
    
            int firstMask = 1<<(p[0]-'a');
            int cnt = 0;
            for(int j = mask; j > 0; j=((j-1)&mask)) {
                if ((j & firstMask) > 0  && freq.count(j)) {
                    cnt+=freq[j];
                }
            }
            res.push_back(cnt);
        }
        return res;
    }
};