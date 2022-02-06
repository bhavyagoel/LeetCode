class Solution {
public:
    int minAddToMakeValid(string s) {
        stack <char> temp; 
        
        int n = s.length();
        int ans = 0; 
        for(int i = 0 ; i < n; i++) {
            if(s[i]==')') {
                if(temp.empty()) {
                    ans++;
                }else{
                    temp.pop(); 
                }
            }
            if(s[i]=='(') {
                temp.push('(');
            }
        }
        
        return ans+temp.size(); 
    }
};