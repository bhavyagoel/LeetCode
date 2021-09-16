class Solution {
public:
    
    bool checkPrime(int n) {
        if(n==1) {
            return false;
        }
        for(int i = 2 ; i <= sqrt(n); i++) {
            if (n%i == 0) {
                return false;
            }
        }
        // cout<<n<<endl;
        return true; 
    }
    
    int countPrimeSetBits(int left, int right) {
        int count = 0; 
        
        for(int i = left; i <= right; i++) {
            if(checkPrime(__builtin_popcount(i))) {
                count++;
            }
        }
        
        return count;
    }
};