class Solution {
public:
    int countHomogenous(string s) {
        return helper(s); 
    }
private:
    int helper(string &s) {
        long long int n = s.size(); 
        long long int res = 0;
        long long int mod = 1000000007;
        for(int i = 0 ; i < n ; i++) {
            char temp = s[i]; 
            long long int count = 0; 
            while(i<n && s[i] == temp) {
                count++;
                count = count % mod;
                i++;
            }
            i--;
            
            res += (((count*(count+1))/2) % mod);
        }
        return res % mod;
    }
};