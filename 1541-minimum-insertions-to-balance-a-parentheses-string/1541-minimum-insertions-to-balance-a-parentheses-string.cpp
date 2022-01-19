class Solution {
public:
    int minInsertions(string s) {
        int i = 0; 
        int n = s.length(); 
        stack<char> stk; 
        
        int ans = 0; 
        while(i<n) {
            if(s[i]=='('){
                stk.push(s[i]);
            }else {
                if(s[i+1]==')') {
                    i++;
                    if(stk.empty()) ans++;
                    else stk.pop();
                }else {
                    if(stk.empty()) ans+=2;
                    else {
                        stk.pop(); 
                        ans += 1;
                    }
                }
            }
            i++;
        }
        
        return ans + stk.size()*2;
    }
};