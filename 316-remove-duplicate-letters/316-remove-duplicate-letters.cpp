class Solution {
public:
    string removeDuplicateLetters(string s) {
        map<char, int> alphaCnt; 
        int inStk[26] = {0};
        stack<char> resStk;
        
        for(auto &it : s ) alphaCnt[it]++;
        
        int len = s.size(); 
        for(int i = 0; i < len; i++) {
            if(resStk.empty()) {
                resStk.push(s[i]);
                inStk[s[i]-'a']=1;
            } else{
                if(inStk[s[i]-'a']==0) {
                    while(!resStk.empty() and resStk.top()>s[i] and alphaCnt[resStk.top()]>0) {
                        inStk[resStk.top()-'a']=0;
                        resStk.pop(); 
                    }
                    resStk.push(s[i]);
                    inStk[s[i]-'a']=1;
                }
            }
            alphaCnt[s[i]]--;
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