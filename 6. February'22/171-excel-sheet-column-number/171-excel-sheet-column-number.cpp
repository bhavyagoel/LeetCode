class Solution {
public:
    int titleToNumber(string c) {
        
        int n = c.size()-1; 
        
        int res = 0; 
        unsigned int mult = 1; 
        while(n>=0){
            res += mult*(c[n]-'A'+1);
            mult *= 26; 
            n-=1; 
        }
        
        return res; 
    }
};