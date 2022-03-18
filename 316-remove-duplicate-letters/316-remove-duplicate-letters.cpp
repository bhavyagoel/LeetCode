class Solution {
public:
    string removeDuplicateLetters(string s) {
        int alphaCnt[26] = {0};
        int inStk[26] = {0};
        string res = "";
        
        for(auto &it : s ) alphaCnt[it-'a']++;
        
        for(auto &it : s) {
            if(inStk[it-'a']==0) {
                while(!res.empty() and res.back()>it and alphaCnt[res.back()-'a']>0) {
                    inStk[res.back()-'a']=0;
                    res.pop_back(); 
                }
                res += it;
            }
            alphaCnt[it-'a']--;
            inStk[it-'a']=1;
        }
        
        return res; 
    }
};