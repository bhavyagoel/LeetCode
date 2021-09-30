class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        
        // Using multiplication & division (analogous to 10)
        // uint32_t num1 = 0; 
        // for(int i = 0 ; i < 32; i++) {
        //     num1 = num1<<1;
        //     num1 += n%2;
        //     n = n/2;
        // }
        
        
        // By reversing bits manipulation 
        // Move original number bit by bit to right, and add it's value to answer number
        // after which shift the answer number to left by 1
        uint32_t num = 0;
        for(int i= 0 ; i < 32; i++, n>>=1) {
            num <<= 1;
            num = num | (n&1);
        }
        
        return num;
    }
};