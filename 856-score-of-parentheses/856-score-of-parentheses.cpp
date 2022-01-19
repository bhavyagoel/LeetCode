class Solution {
public:

    int scoreOfParentheses(string s) {
        
        int n = s.length(); 
        int res=0, bal=0;
        for(int i = 0; i< n; i++) {
            if (s[i]=='(') {
                bal++;
            }else{
                bal--;
                if(s[i-1]=='('){
                    res += 1<<bal;
                }
            }
        }
        return res;
    }    
};