class Solution {
public:
    bool isPalindrome(string s) {
        
        string res(""); 
        int len = 0; 
        
        for(auto i : s) {
            if(iswalnum(i)) {
                res += tolower(i);
                len++;
            }
        }
        
        // cout<<res;
        int j = len-1;
        for(int i = 0 ; i < len/2; i++) {
            if(res[i] != res[j]) {
                return false;
            }
            j--;
        }
        
        
        return true;
    }
};