class Solution {
public:
    int hammingWeight(uint32_t n) {
        int k = 0;
        while(n != 0) {
            n &= n - 1;
            k++;
        }
        return k;
    }
};