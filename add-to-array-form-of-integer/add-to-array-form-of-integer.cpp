class Solution {
public:
    vector<int> addToArrayForm(vector<int>& num, int k) {
        vector<int> res; 
        
        int n = num.size(); 
        int carry = 0; 
        for(int i = n-1; i>-1; i--) {
            num[i] = num[i] + k%10 + carry;
            k = k/10;
            carry = num[i]/10;
            num[i] = num[i]%10;
        }
        
        while(k) {
            num.insert(num.begin(), k%10 + carry);
            carry = num[0]/10;
            num[0] = num[0]%10; 
            
            k = k/10;
        }  
        
        if(carry>0) {
            num.insert(num.begin(), carry);
        }
        return num; 
    }
};