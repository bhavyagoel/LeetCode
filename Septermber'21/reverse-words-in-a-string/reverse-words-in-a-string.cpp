class Solution {
public:
    string reverseWords(string s) {
        
        
        int n = s.size(); 
        
        int len = n;
        for(int i = 0 ; i < n; i++) {
            if(s[i] == ' ') {
                if(s[i+1] == ' ') {
                    s.erase(s.begin() + i + 1);
                    i--;
                    len--;
                }
            }
            
            if(s[0] == ' ') {
                s.erase(s.begin());
                len--;
            }
            if(s[len-1] == ' ') {
                s.pop_back(); 
                len--;
            }
        }
        
        
        // Removing spaces present at last
        // int last = n-1; 
        // while(s[last] == ' ') {
        //     s.pop_back();
        //     last--;
        // }
        
        // Reversing the string
        n = s.size(); 
        for(int i = 0 ; i < ceil(n/2); i++) {
            char swap = s[i]; 
            s[i] = s[n-i-1];
            s[n-i-1] = swap;
        }
        
        // Removing spaces present at reversed last
        // last = n-1; 
        // while(s[last] == ' ') {
        //     s.pop_back();
        //     last--;
        // }
        
        // Removing repetitive spaces present between words
        // n = s.size(); 
        // for(int i = 0 ; i < n; i++) {
        //     if(s[i] == ' ') {
        //         if(s[i+1] == ' ') {
        //             s.erase(s.begin() + i + 1);
        //             i--;
        //         }
        //     }
        // }
        
        // Reversing each word present in the string
        for(int i = 0 ; i < n; i++) {
            int start = i; 
            int places = i;
            while(s[i] != ' ' && i < n) {
                places++;
                i++;
            }            
            for(int j = start; j < floor((places+start)/2); j++) {
                swap(s[j], s[(places+start)-j-1]);
            }
        }
        
        return s;
    }
};