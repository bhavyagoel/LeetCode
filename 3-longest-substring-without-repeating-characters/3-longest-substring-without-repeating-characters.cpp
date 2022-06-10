class Solution {
public:
   int lengthOfLongestSubstring(string s) {
        vector<int> dict(256, -1);
        int maxLen = 0, start = -1;
        for (int i = 0; i != s.length(); i++) {
            if (dict[s[i]] > start)
                start = dict[s[i]];
            dict[s[i]] = i;
            maxLen = max(maxLen, i - start);
        }
        return maxLen;
    }
};


/*
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int max_len = 0;
        for(int i = 0 ; i < s.length(); i++) {
            map<char, int> temp; 
            int len = 0; 
            for(int j = i; j < s.length(); j++) {
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
*/