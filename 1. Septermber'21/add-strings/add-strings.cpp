class Solution {
public:
    string addStrings(string s1, string s2) {
        string res = ""; 
        
        int n = max(s1.size(), s2.size()); 
        int carry = 0; 
        for(int i = 0 ;i < n; i++) {
            int num1 = 0; 
            int num2 = 0; 
            if(s1 != "") {
                num1 = s1.back() - '0'; 
                s1.pop_back();
            }
            if (s2 != "") {
                num2 = s2.back() - '0';
                s2.pop_back();
            }
            
            int ans = num1 + num2 + carry; 
            carry = 0;
            if(ans > 9) {
                carry = ans/10; 
                ans = ans%10; 
            }
            res += to_string(ans);
        }
        if(carry > 0) {
            res += to_string(carry);
        }
        
        reverse(res.begin(), res.end());
        return res;
    }
};