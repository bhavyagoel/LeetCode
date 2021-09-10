#define int_l long long int

class Solution {
public:
    string shiftingLetters(string s, vector<int>& shifts) {
        int_l n = shifts.size(); 
        
        int_l sum = 0;
        
        for(int_l i = n-1; i > -1; i--) {
            sum += shifts[i];
            s[i] = (s[i] - 'a' + sum)%26 + 'a';            
        }
        
        
        return s;
    }
};