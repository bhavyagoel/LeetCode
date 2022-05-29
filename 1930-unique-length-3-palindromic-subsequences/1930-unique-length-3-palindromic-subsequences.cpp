/*
class Solution {
public:
    int countPalindromicSubsequence(string s) {
        
        map<char, int> cnt; 
        int res = 0; 
        int n = s.size(); 
        vector<int>unq(26,0);
        bool check[26][26] = {false};

        for(int i = 0; i < n; i++) {
            unq[s[i]-'a'] |= (1 << (s[i]-'a'));
            cnt[s[i]]++;
            
            while(i<n-1 and s[i]==s[i+1]) cnt[s[i++]]++;
            if(cnt[s[i]]) {
                int temp = unq[s[i]-'a'];
                while(temp) {
                    int r = __builtin_ctz(temp & -temp);
                    temp ^= (temp & -temp); 
                    if(!check[s[i]-'a'][r] and r != (s[i]-'a')) {
                        res += 1;
                        check[s[i]-'a'][r] = true;
                    }
                }                
                if(cnt[s[i]] > 2 and !check[s[i]-'a'][s[i]-'a']) {
                    res += 1;
                    check[s[i]-'a'][s[i]-'a'] = true;
                }
                unq[s[i]-'a'] &= (1 << (s[i]-'a'));
            }
            
            for(int j = 0; j < 26; j++) {
                if(unq[j]) unq[j] |= (1 << (s[i]-'a'));
            }
        }
        return res;
    }
};
*/

// Can be solved by calculating first and last occurence of each alphabet, and then counting the unique alphabets between those
class Solution {
public:
    int countPalindromicSubsequence(string s) {
        int first[26] = {[0 ... 25] = INT_MAX}, last[26] = {}, res = 0;
        for (int i = 0; i < s.size(); ++i) {
            first[s[i] - 'a'] = min(first[s[i] - 'a'], i);
            last[s[i] - 'a'] = i;
        }
        for (int i = 0; i < 26; ++i)
            if (first[i] < last[i])
                res += unordered_set<char>(begin(s) + first[i] + 1, begin(s) + last[i]).size();
        return res;
    }
};