class Solution {
public:
    int arrangeCoins(int n) {
        
        int count = 0; 
        int step = 1;
        while(n >= 0) {
            n = n - step;
            step++;
            count++;
        }
        
        return count-1;
    }
};