class Solution {
public:
    int maxPower(string s) {
        return helper(s);
    }
    
private:
    int helper(string &s) {
        int n = s.size(); 
        int res = INT_MIN;
        for(int i = 0 ; i < n; i++) {
            char temp = s[i]; 
            int count = 0; 
            while(s[i] == temp) {
                count++;
                i++;
            }
            res = max(count, res);
            i--;
            
        }
        return res;
    }
};