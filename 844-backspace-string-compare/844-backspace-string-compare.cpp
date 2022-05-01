class Solution {
public:
    bool backspaceCompare(string s, string t) {       
        int i = s.size() - 1; 
        int j = t.size() - 1; 
        
        int t_bk = 0; 
        int s_bk = 0;
        
        while(i >= 0 or j >= 0) {
            while(i>=0) {
                if(s[i]=='#') {
                    s_bk += 1; 
                    i -= 1; 
                }
                else if(s_bk) {
                    s_bk -= 1; 
                    i -= 1; 
                }
                else break;
            }
            while(j>=0) {
                if(t[j]=='#') {
                    t_bk += 1; 
                    j -= 1; 
                }
                else if(t_bk) {
                    t_bk -= 1; 
                    j -= 1; 
                }
                else break;
            }
            
            if(i>=0 and j>=0 and !t_bk and !s_bk and s[i] != t[j]) return false; 
            if ((i >= 0) != (j >= 0))return false;
            i -= 1; 
            j -= 1;
        }
        return true; 
    }
};