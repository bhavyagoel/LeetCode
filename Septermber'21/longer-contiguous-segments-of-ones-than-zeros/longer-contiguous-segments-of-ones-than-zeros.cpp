class Solution {
public:
    bool checkZeroOnes(string s) {
        int lenZero = 0; 
        int lenOne = 0;
        
        int maxLenOne = INT_MIN; 
        int maxLenZero = INT_MIN; 
        
        for(auto i : s) {
            if (i == '0') {
                lenZero += 1;
                lenOne = 0;
                
                if(maxLenZero < lenZero) {
                    maxLenZero = lenZero;
                }
                
            }
            
            else if (i == '1') {
                lenOne += 1;
                lenZero = 0;
                
                if(maxLenOne < lenOne) {
                    maxLenOne = lenOne;
                }
                
            }
        }
        
        
        if(maxLenOne > maxLenZero) {
            return true;
        }
        
        return false;
    }
};