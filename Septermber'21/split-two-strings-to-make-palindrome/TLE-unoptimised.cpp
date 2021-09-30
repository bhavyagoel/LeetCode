class Solution {
public:
    bool checkPalindromeFormation(string a, string b) {
        
        string a_rev = a; 
        reverse(a_rev.begin(), a_rev.end());
        
        string b_rev = b; 
        reverse(b_rev.begin(), b_rev.end());
        
        
        int n = a.size(); 

        for(int i = 0 ; i < n; i++) {
            
            string check = a.substr(0, i) + b.substr(i,n);
            string check_rev =  b_rev.substr(0, n-i) + a_rev.substr(n-i, n);
            if(check == check_rev) {
                return true;
            }
        }
        
        for(int i = 0 ; i < n; i++) {
            string check = b.substr(0, i) + a.substr(i,n);
            string check_rev =  a_rev.substr(0, n-i) + b_rev.substr(n-i, n);
            if(check == check_rev) {
                return true;
            }
        }
        
        return false; 
        
    }
};
