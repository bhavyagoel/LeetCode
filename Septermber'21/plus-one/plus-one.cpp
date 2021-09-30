class Solution {
public:
    vector<int> plusOne(vector<int>& num) {
        
        int n = num.size(); 
        int carry = 0; 
        int k = 1; 
        for(int i = n-1; i>-1; i--) {
            num[i] = num[i] + k%10 + carry;
            k = k/10;
            carry = num[i]/10;
            num[i] = num[i]%10;
        }
        
         if(carry>0) {
            num.insert(num.begin(), carry);
        }
        return num; 
    }
};