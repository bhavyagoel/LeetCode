class Solution {
public:
    string replaceDigits(string s) {
        
        int n = s.length(); 
        
        int prevVal;
        for(int i = 0 ; i < n; i++) {
            
            if((i+1)%2 == 0){
                s[i] = s[i] - '0' + prevVal;
            }
            else {
                prevVal = s[i];
            }
        }
        
        return s;
    }
};