class Solution {
public:
    void reverseString(vector<char>& s) {
        
        int n = s.size(); 
        
        for(int i = 0 ; i < ceil(n/2); i++) {
            char swap = s[i]; 
            s[i] = s[n-i-1];
            s[n-i-1] = swap;
            
        }
    }
};