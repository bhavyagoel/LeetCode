class Solution {
public:
    bool halvesAreAlike(string s) {
        int n = s.size();
        
        return (helper(s.substr(0, n/2)) == helper(s.substr(n/2, n)));
    }
    
private:
    int helper(string s) {
        int res = 0; 
        for(auto &i : s) {
            i = tolower(i); 
            if(i == 'a' || i == 'e' || i == 'i' || i=='o' || i=='u') {
                res++;
            }
        }
        return res;
    }
};