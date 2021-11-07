class Solution {
public:
    
    // To multiply single number with a string
    string multiply(char &a, string &s) {
        string res = "";
        int alpha = a - '0';
        int n = s.size(); 
        int carry = 0; 
        for(int i = n-1; i > -1; i--) {
            int num = alpha * (s[i] - '0') + carry; 
            carry = 0; 
            if(num  > 9) {
                carry = num/10; 
                num = num%10; 
            }
            
            res += to_string(num);
        }
        
        if(carry > 0) {
            res += to_string(carry);
        }
        
        reverse(res.begin(), res.end());
        return res; 
    }
    
    
    // Function to add two strings
    string add2string(string &s1, string &s2) {
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
    
    // Function to add n string
    string addNstring(vector<string> &alpha) {
        string res = alpha[0];
        
        int n = alpha.size(); 
        for(int i = 1 ; i < n; i++) {
            res = add2string(res, alpha[i]);
        }
        return res;
    }
    
    
    string multiply(string num1, string num2) {
        
        vector<string> mul; 
        int n = num1.size(); 
        int num_zeros = 0;
        
        if(num1 == "0" || num2 == "0") {
            return "0";
        }
        
        for(int i = n-1 ; i > -1; i--) {
            string alpha = multiply(num1[i], num2);
            
            for(int j = 0 ; j < num_zeros; j++) {
                alpha += '0';
            }
            num_zeros++;
            // reverse(alpha.begin(), alpha.end());
            mul.push_back(alpha);
        }
        
        
        return addNstring(mul); 
    }
};