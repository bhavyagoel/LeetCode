class Solution {
public:
    stack<string> reverse(stack<string> stk) {
        stack<string> res; 
        while(!stk.empty()){
            res.push(stk.top());
            stk.pop();
        }
        return res; 
    }
    
    
    string simplifyPath(string s) {
        stack<string> dir; 
        int i = 0; 
        int len = s.length(); 
        
        while(i<len) {
            if(s[i]=='/') {
                i++;
                continue; 
            }
            string temp = "";
            while(i<len and s[i]!='/') {
                temp += s[i];
                i++;
            }
            
            if(temp==".."){
                if(!dir.empty()) dir.pop(); 
            }
            else if(temp!=".") {
                dir.push(temp); 
            }
            i++;
        }
        
        
        string res = "/";
        dir = reverse(dir);

        while(!dir.empty()) {
            res+=dir.top();
            dir.pop(); 
            res+='/';
        }
        
        res.pop_back(); 
        if(res.size()==0) return "/";
        return res; 
    }
};