class Solution {
public:
    int numberOfSubstrings(string s) {
        
        int a = 0, b = 0, c = 0; 
        int i = 0, j = 0; 
        int res = 0; 
        
        
        while(i<=j){
            while(j<s.size() and (!a or !b or !c )) {
                if(s[j]=='a') a++;
                else if (s[j]=='b') b++;
                else c++;
                j++;
            }
            if(a and b and c) res += s.size() - j + 1;
            if(s[i]=='a') a--;
            else if (s[i]=='b') b--;
            else c--;
            i++;
        }
        return res;
    }
};