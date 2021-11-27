class Solution {
public:
    int characterReplacement(string s, int k) {
        
        vector<int> alpha(26,0);
        int same = INT_MIN;
        int len = 0;
        int start = 0;
        int res = INT_MIN;
        for(int i = 0; i < s.length(); i++) {
            int tmp;
            int temp = s[i]-'A';
            alpha[temp]++;
            
            if(alpha[temp]>same){
                same = alpha[temp];
                tmp = temp;
            }
            
            len++;
            int diff = len - same;
            
            while(diff > k) {
                if (s[start]-'A'!=tmp) diff--;
                alpha[s[start]-'A']--;
                start++;
                len--;
                diff = len - same;
            }            
            res = max(res, len);
        }
        
        return res;
    }
};