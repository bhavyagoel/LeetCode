// Sieve of erastothenes

class Solution {
public:
    int countPrimes(int n) {
        return helper(n);
    }
private:
    int helper(int &n) {
        vector<bool> alpha(n);
        
        for(int i = 2 ; i < n; i++) {
            alpha[i]  = true;
        }
        
        
        for(int i = 2; i*i < n; i++) {
            if(alpha[i]) {
                for(int j = i*i; j< n; j+=i) {
                    alpha[j] = false;   
                }
            }
            
        }
        
        int count = 0; 
        for(int i = 2; i<n; i++) {
            if(alpha[i]) {
                count++;
            }
        }
        
        return count;
    }
};