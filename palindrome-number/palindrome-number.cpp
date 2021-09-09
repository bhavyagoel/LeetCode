class Solution {
public:
    bool isPalindrome(int x) {
        if(x<0) {
            return false;
        }
        
        long long int revNum = 0; 
        int Num = x;
        while(x) {
            int rem = x%10;
            x = x/10;
            revNum *= 10;
            revNum += rem;
        }
        
        if(Num != revNum) {
            return false;
        }
        
        return true; 
    }
};