class Solution {
public:
    int numSteps(string s) {
        
        int n = s.size()-1; 
        int res = 0; 
        while(s.size()!=1) {
            if(s.back()=='0') {
                s.pop_back();
                res++;
            }
            else {
                int i = s.size()-1; 
                while(i>-1 and s[i]=='1') {
                    s[i]='0';
                    i--;
                }
                
                if(i>=0) s[i] = '1';
                else {
                    s.insert(0 , "1");
                }
                res++;
            }
        }
        
        if(s[0]=='1') return res;
        return res+1;
    }
};