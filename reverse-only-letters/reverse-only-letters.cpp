class Solution {
public:
    string reverseOnlyLetters(string s) {
        int n = s.size(); 
        
        int j = n-1; 
        int i = 0; 
        
        while(i<j) {
            if (!isalpha(s[i])) {
                i++;
            }
            if (!isalpha(s[j])) {
                j--;
            }
            
            if(isalpha(s[i]) && isalpha(s[j])) {
                char swap = s[i];
                s[i] = s[j];
                s[j] = swap;
                i++;
                j--;
            }

        }
        
        return s;
    }
};