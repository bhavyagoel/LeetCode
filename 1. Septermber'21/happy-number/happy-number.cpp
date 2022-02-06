class Solution {
public:
    bool isHappy(int n) {
        
        
        int sum = 0; 
        while(n){
            sum += pow(n%10, 2);
            n /=10; 
        }
        
        if(sum < 5 && sum!=1){
            return false;
        }
        
        if(sum==1) {
            return true;
        }
        return isHappy(sum); 
    }
};