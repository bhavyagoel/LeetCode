class Solution {
public:
   
    bool wordPattern(string pattern, string s) {
        
        vector<string>alpha; 

        string temp = "";
        int j = 0; 
        alpha.push_back("");
        for(auto i : s) {
            if(i == ' ') {
                j++;
                alpha.push_back("");
            }else {
                alpha[j] += i; 
            }
        }
        
       
        if(pattern.length() != alpha.size()){
            return false; 
        }
        
        map<char, string> beta; 
        j = 0; 
        map<string, int> gamma;
        for(auto i: pattern) {
            if(beta[i] == "") {
                if(gamma[alpha[j]] != 1) {
                    beta[i] = alpha[j]; 
                    gamma[alpha[j]] = 1;
                }
                else {
                    return false; 
                }
                
            }
            else {
                if(beta[i] != alpha[j]) {
                    return false; 
                }
            }
            j++;
        }
        return true; 
    }
};