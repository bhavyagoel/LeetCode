class Solution {
public:
    string minRemoveToMakeValid(string s) {
        
        int n = s.length(); 
        int count = 0; 
        for(int i = 0; i < n; i++) {
            if (s[i]=='('){
                count++;
            }
            if (s[i]==')') {
                if(count==0) {
                    s[i]='#';
                }else{
                    count--;
                }
            }
        }
        
        count = 0;
        for(int i = n-1; i >-1; i--) {
            if (s[i]==')'){
                count++;
            }
            if (s[i]=='(') {
                if(count==0) {
                    s[i]='#';
                }else{
                    count--;
                }
            }
        }
        
        string res;
        for(int i = 0; i < n; i++) {
            if(s[i]!='#'){
                res+=s[i];
            }
        }
        return res; 
    }
};