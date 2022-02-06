class Solution {
public:
    vector<string> printVertically(string s) {
        
        int n = s.length(); 
        int m = 0;
        vector<string> w;
        string word = "";
        int i = 0;
        while(i<n) {
            while(i<n and s[i]!=' ') {
                word += s[i];
                i++;
            }
            m = max(m, (int)word.length());
            w.push_back(word);
            word = "";
            i++;
        }
        
        for(int i = 0; i < w.size(); i++) {
            if(w[i].length()<m) {
                string space(m-w[i].length(), ' ');
                w[i] += space;
            }
        }
        
        m = w.size(); 
        n = w[0].length();
        vector<string> res;
        for(i = 0; i < n; i++) {
            word = "";
            for(int j = 0; j < m; j++) {
                word += w[j][i];
            }
            
            while(word.back()==' '){
                word.pop_back();
            } 
            res.push_back(word);
        }
        
        return res;
    }
};