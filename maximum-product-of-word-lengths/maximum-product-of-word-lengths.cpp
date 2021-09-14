class Solution {
public:
    
    bool stringCheck(string s1, string s2) {
        
        map<char, int> alpha1; 
        map<char, int> alpha2;
        
        for(int i = 0; i < s1.size(); i++) {
            alpha1[s1[i]] = 1;
        }
        
        for(int i = 0 ; i < s2.size(); i++) {
            alpha2[s2[i]] = 1;
        }
        
        for(auto i: alpha1) {
            if(alpha2[i.first]) {
                return true;
            }
        }
        return false;
    }
    
    int letterBits(string s) {
        int bits = 0;
        
        for(auto ch : s){
            bits |= 1 << (ch - 'a');
        }
        return bits;
    }
    
    int maxProduct(vector<string>& words) {
        
        
        int n = words.size(); 
        
        int max = 0;
        
        vector<int> bits(n); 
        
        for(int i = 0 ; i < n; i++) {
            bits[i] = letterBits(words[i]);
        }
        for(int i = 0 ; i < n-1; i++) {
            for(int j = i+1; j<n; j++) {
                if ((bits[i] & bits[j]) == 0) {
                    int mul = words[i].size() * words[j].size(); 
                    if(mul > max) {
                        max = mul;
                    }
                }
            }
        }
        
        return max;
    }
};