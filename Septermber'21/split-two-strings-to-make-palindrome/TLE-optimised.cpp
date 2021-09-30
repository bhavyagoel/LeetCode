class Solution {
public:
    
    bool checkPalind(string &a, string &b, int index) {

        int n = a.size();
        if (index < n/2) {
            
            for(int i = 0 ; i < index; i++) {
                if(a[i] != b[n-i-1]) {
                    return false; 
                }

            }
            
            for(int i = index; i < n-index; i++) {
                if(b[i] != b[n-i-1]) {
                    return false; 
                }
            }
        }
        
        else {
            for(int i = 0 ; i < n-index; i++) {
                if(a[i] != b[n-i-1]) {
                    return false; 
                }

            }
            
            for(int i = n-index; i < index; i++) {
                if(a[i] != a[n-i-1]) {
                    return false; 
                }
            }
        }
        
        
        return true;
    }
    
    bool checkPalindromeFormation(string a, string b) {
        
        int n = a.size(); 
        if(n==1) {
            return true;
        }
        
        
        for(int i = 0 ; i < n; i++) {
            if(checkPalind(a, b, i) || checkPalind(b, a, i)) {
                return true; 
            }
        }

        return false; 
        
    }
};
