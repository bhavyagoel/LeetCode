class Solution {
public:
    int lengthOfLastWord(string s) {
        return helper(s); 
    }
    
private:
    int helper(string &s) {
        int n = s.size()-1; 
        
        while(n>-1 && s[n] == ' ') {
            s.pop_back(); 
            n--;
        }

        n = s.size()-1;
        int count = 0;
        do{
            count++;
            n--;
            if(n<0) {
                break;
            }
        }while(s[n]!=' ' && n>-1);
        
        return count; 
    }
};