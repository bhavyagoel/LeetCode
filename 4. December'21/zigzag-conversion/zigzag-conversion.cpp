class Solution {
public:
    string convert(string s, int numRows) {
        string res;
        if(s.length() <= numRows or numRows==1) return s;
        
        int n = s.length();
        for(int i = 0; i < n; i+=2*(numRows - 1)) {
            res.push_back(s[i]);
        }
        
        for(int i = 1; i < numRows-1; i++) {
            int j = i; 
            res.push_back(s[i]);
            while(j < n) {
                j += 2*(numRows-i-1);
                if(j >= n) break;
                res.push_back(s[j]);
                
                j += 2*i; 
                if(j >= n) break;
                res.push_back(s[j]);
            }
        }
        
        for(int i = numRows - 1; i < n; i+=2*(numRows - 1)) {
            res.push_back(s[i]);
        }
        
        return res; 
    }
};