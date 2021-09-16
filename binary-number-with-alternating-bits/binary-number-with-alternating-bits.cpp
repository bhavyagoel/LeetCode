class Solution {
public:
    bool hasAlternatingBits(int n) {
        
        
        
        
        // LSB is zero 
        if ((n & 1) == 0) {
            long long int num = 1; 
            for(int i = 0 ;i < ceil(log2(n)); i++) {
                if(i%2 == 0) {
                    if( (num & n) != 0){
                        return false;
                    }
                }
                
                else {
                    if( (num & n) == 0){
                        return false;
                    }
                }
                num = num <<1;
            }
        }
        
        // LSB is 1
        else {
            long long int num = 1; 
            for(int i = 0 ;i < ceil(log2(n)); i++) {
                if(i%2 != 0) {
                    if( (num & n) != 0){
                        return false;
                    }
                }
                else {
                    if( (num & n) == 0){
                        return false;
                    }
                }
                num = num << 1;
            }
        }
        
        return true;
    }
};