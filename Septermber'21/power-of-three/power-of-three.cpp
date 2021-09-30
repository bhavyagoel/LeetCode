class Solution {
public:
    bool isPowerOfThree(int n) {
        
        int maxPow = pow(3,19);
        return ((n>0) && (maxPow % n == 0));
    }
};