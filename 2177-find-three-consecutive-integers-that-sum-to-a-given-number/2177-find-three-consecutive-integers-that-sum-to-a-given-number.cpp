class Solution {
public:
    vector<long long> sumOfThree(long long num) {
        
        
        if(num%3) return {};
            
        num /= 3; 

        return {num-1, num, num+1};
        
    }
};