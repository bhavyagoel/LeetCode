class Solution {
public:
    bool isUgly(int n) {
        if(n==0) {
            return false;
        }
        if(n%2 == 0) {
            return isUgly(n/2);
        }
        else if(n%3 == 0){
            return isUgly(n/3);
        }
        else if(n%5 == 0){
            return isUgly(n/5);
        }
        else if (n!=1){
            return false; 
        }
        
        return true; 
    }
};