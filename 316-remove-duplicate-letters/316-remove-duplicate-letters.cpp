class Solution {
public:
    string removeDuplicateLetters(string s) {
        int alphaCnt[26] = {0};
        int inStk[26] = {0};
        stack<char> resStk;
        
        for(auto &it : s ) alphaCnt[it-'a']++;
        
        int len = s.size(); 
        for(int i = 0; i < len; i++) {
            if(resStk.empty()) {
                resStk.push(s[i]);
            } else{
                if(inStk[s[i]-'a']==0) {
                    while(!resStk.empty() and resStk.top()>s[i] and alphaCnt[resStk.top()-'a']>0) {
                        inStk[resStk.top()-'a']=0;
                        resStk.pop(); 
                    }
                    resStk.push(s[i]);
                }
            }
            alphaCnt[s[i]-'a']--;
            inStk[s[i]-'a']=1;
        }
        
        
        string res = "";
        while(!resStk.empty()){
            res += resStk.top(); 
            resStk.pop(); 
        }
        reverse(res.begin(), res.end()); 
        return res; 
    }
};