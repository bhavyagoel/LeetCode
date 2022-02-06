// https://leetcode.com/problems/find-the-longest-substring-containing-vowels-in-even-counts/discuss/534135/C%2B%2BJava-with-picture

class Solution {
public:
    int findTheLongestSubstring(string s) {
        int vowels[26] = {0};
        vowels['a'-'a'] = 1;
        vowels['e'-'a'] = 2;
        vowels['i'-'a'] = 4; 
        vowels['o'-'a'] = 8; 
        vowels['u'-'a'] = 16; 
        
        vector<int> mask(32,-1);
        int msk = 0; 
        int res = INT_MIN; 
        for(int i = 0 ; i < s.length(); i++) {
            msk ^= vowels[s[i]-'a'];
            if(msk != 0 and mask[msk]==-1){
                mask[msk] = i; 
            }
            
            res = max(res, i-mask[msk]);
        }
        return res; 
    }
};