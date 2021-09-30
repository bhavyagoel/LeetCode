class Solution {
public:
    int hammingWeight(uint32_t n) {
        
        int count = 0;
        long long int num = 1; 
        
        
        for(int i = 0; i < 32; i++) {
            
            if((n & num) != 0) {
                count++;
            }
            num = num << 1;
        }
        
        return count;
    }
};