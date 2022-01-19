class Solution {
public:
    bool checkValidString(string s) {
        stack<char> stk;
        stack<char> star; 
        int n = s.length(); 

        int i = 0;
        while(i<n) {
            if(stk.empty() and s[i]==')') {
                return false;
            }
            
            while(s[i]=='(' or s[i]=='*') {
                stk.push(s[i]);
                i++;
            }
            
            while(s[i]==')') {
                if(stk.empty() and s[i]==')') {
                    return false; 
                }
                
                while(!stk.empty() and stk.top() == '*'){
                    stk.pop(); 
                    star.push('*');
                }
                
                if(!stk.empty() and stk.top()=='(') {
                    stk.pop();
                    i++;
                    while(!star.empty()) {
                        stk.push('*');
                        star.pop();
                    }
                    continue;
                }
                if(star.empty() and !stk.empty() and stk.top()==')') {
                    return false; 
                }
                star.pop();
                while(!star.empty()) {
                    stk.push('*');
                    star.pop();
                }
                i++;
            }
        }
        
        int str = 0; 
        int opening = 0; 
        while(!stk.empty()){
            if(stk.top()=='*') str++;
            if(stk.top()=='(') {
                if(str==0) return false;
                str--;
            }
            stk.pop();
        }
        return true;
    }
};