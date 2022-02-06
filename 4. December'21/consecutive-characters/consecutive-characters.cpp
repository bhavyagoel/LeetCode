class Solution {
public:
    int maxPower(string s) {
        
        int n = s.length(); 
        int res = 0; 
        
        for(int i = 0; i < n; i++) {
            int len = 0; 
            char curr = s[i]; 
            
            while(curr==s[i]){
                len++;
                i++;
            }
            i--;
            res = max(res, len); 
        }
        return res;
    }
};