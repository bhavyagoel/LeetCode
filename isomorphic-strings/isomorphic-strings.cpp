class Solution {
public:
    bool isIsomorphic(string s, string t) {
        if (s.length() != t.length()) {
            return false; 
        }
        
        map <char,char> alpha; 
        map <char,int> beta; 
        int j = 0; 
        for(auto i: s) {
            if(!alpha[i]) {
                if(beta[t[j]] != 1) {
                    alpha[i] = t[j];
                    beta[t[j]] = 1;
                }
                else {
                    return false; 
                }
                
            }
            else {
                if( alpha[i] != t[j]) {
                    return false; 
                }
            }
            j++;
        }
        return true;    
    }
};