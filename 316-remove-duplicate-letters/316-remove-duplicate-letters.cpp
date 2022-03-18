class Solution {
public:
    string removeDuplicateLetters(string s) {
        int alphaCnt[26] = {0};
        int inStk[26] = {0};
        string res = "";
        
        for(auto &it : s ) alphaCnt[it-'a']++;
        
        int len = s.size(); 
        for(int i = 0; i < len; i++) {
            if(inStk[s[i]-'a']==0) {
                while(!res.empty() and res.back()>s[i] and alphaCnt[res.back()-'a']>0) {
                    inStk[res.back()-'a']=0;
                    res.pop_back(); 
                }
                res += s[i];
            }
            alphaCnt[s[i]-'a']--;
            inStk[s[i]-'a']=1;
        }
        
        return res; 
    }
};