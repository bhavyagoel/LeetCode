class Solution {
public:
    bool isPowerOfFour(int n) {
        
        if(n == 0) {
            return false;
        }
        return (floor(log(n)/log(4)) == ceil(log(n)/log(4)));
    }
};