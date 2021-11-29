class Solution {
public:
    string reverseParentheses(string s) {
        
        stack <char> temp;        
        int n = s.length(); 
        string res = "";
        int open = 0; 
        int start = 0; 
        
        while(s[start] != '(' and start<n) {
            res += s[start];
            start++;
        }
        
        for(int i = start; i < n; i++) {
            if(s[i]=='(') {
                temp.push(s[i]);
                open++;
            }
            
            else if (s[i]==')') {
                string tmp;
                open--;
                while(temp.top()!='(') {
                    char alpha = temp.top(); 
                    temp.pop(); 
                    tmp.push_back(alpha);
                }
                temp.pop(); 
                if(open) {
                    for(auto chr : tmp) {
                        temp.push(chr);
                    }
                }else{
                    i++;
                    res+=tmp;
                    while(s[i] != '(' and i<n) {
                        if(s[i]!=')') res += s[i];
                        i++;
                    }
                    i--;
                }
            }
            else temp.push(s[i]);
        }
        return res;
    }
};