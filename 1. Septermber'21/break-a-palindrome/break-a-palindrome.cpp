class Solution {
public:
    string breakPalindrome(string palindrome) {
        return helper(palindrome);
    }
    
private:
    string helper(string &s) {
        int n = s.size(); 
        
        if(n<=1) {
            return "";
        }
        
        bool flag = false; 
        
        for(int i = 0 ; i < n/2 ; i++) {
            if(s[i] != 'a') {
                s[i] = 'a';
                flag = true;
                break;
            }
        }
        
        if(!flag) {
            s[n-1] = 'b';
        }
        return s;
        
    }
};