class Solution {
public:
    vector<int> partitionLabels(string s) {
        return helper(s);
    }
private:
    vector<int> helper(string &s) {
        vector<int> res;
        int n = s.length();
        unordered_map <char, int> last;
        
        for(int i = 0; i < n; i++) {
            last[s[i]] = i+1;
        }
        
        for(int i = 0 ; i < n; i++) {
            int pos = last[s[i]];
            int count = 0; 
            for(int j = i; j < pos; j++) {
                pos = max(pos, last[s[j]]);
                count++;
            }
            
            res.push_back(count);
            i = pos-1;
        }
        
        return res; 
    }
};