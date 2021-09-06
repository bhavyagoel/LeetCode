class Solution {
public:
    string addBinary(string a, string b) {
        vector<int> a_bin;
        vector<int> b_bin;
        vector<int> ans;
        
        for(auto i : a) {
            a_bin.push_back(i - '0');
        }
        
        for(auto i : b) {
            b_bin.push_back(i - '0');
        }
        
        int a_len = a_bin.size() - 1;
        int b_len = b_bin.size() - 1;
        
        int carry = 0;
        
        
        while(a_len>=0 || b_len>=0) {
            int flag = carry;
            
            if (a_len >= 0) {
                flag += a_bin[a_len];
                a_len--;
            }
            
            if (b_len >= 0) {
                flag += b_bin[b_len];
                b_len--;
            }
            
            carry = 0;
            if(flag >=2) {
                flag = flag%2;
                carry = 1;
            }
            ans.push_back(flag);
        }
        
        if (carry > 0) {
            ans.push_back(carry);
        }
        string fin;
        for(auto i : ans) {
            fin += to_string(i);
        } 
        
        reverse(fin.begin(), fin.end());
        
        return fin;
    }
};