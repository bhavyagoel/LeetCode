class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int max_len = 0;
        for(int i = 0 ; i < s.length(); i++) {
            map<char, int> temp; 
            int len = 0; 
            for(int j = i ; j < s.length(); j++) {
                if(temp[s[j]] == 0) {
                    len++; 
                    temp[s[j]] = 1;
                }else {
                    break;
                }
                
            }
            max_len = max(max_len, len);
        }
        
        return max_len;
    }
};