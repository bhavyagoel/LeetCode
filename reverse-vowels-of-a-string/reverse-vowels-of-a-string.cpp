class Solution {
public:
    string reverseVowels(string s) {
        vector<int> vw; 
        int n = s.size(); 
        
        for(int i = 0 ; i < n ; i++) {
            if (s[i] == 'a' | s[i]=='A' | s[i]=='e' | s[i]=='E' | s[i]=='i' | s[i]=='I' | 
                s[i]=='o' | s[i]=='O' | s[i]=='u' | s[i]=='U') {
                vw.push_back(i); 
            }
        }
        
        n = vw.size();
        for(int i = 0 ; i < ceil(n/2); i++) {
            char swap = s[vw[i]];
            s[vw[i]] = s[vw[n-i-1]];
            s[vw[n-i-1]] = swap;
        }
        return s;
    }
};