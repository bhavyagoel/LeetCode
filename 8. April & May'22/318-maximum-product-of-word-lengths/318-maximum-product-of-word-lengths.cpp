class Solution {
public:   
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
                if (!(bits[i] & bits[j])) {
                    int mul = words[i].size() * words[j].size(); 
                    if(mul > max) max = mul;
                }
            }
        }
        
        return max;
    }
};