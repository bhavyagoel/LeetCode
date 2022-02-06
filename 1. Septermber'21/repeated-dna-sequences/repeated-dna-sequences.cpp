class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        return helper(s); 
    }
    
private:
    vector<string> helper(string &s) {
        map<string, int> alpha; 
        vector<string> res;
        int n = s.size(); 
        
        for(int i = 0; i < n-9; i++) {
            string s1 = "";
            
            for(int j = i; j < i+10; j++) {
                s1+= s[j];
            }
            
            alpha[s1] = alpha[s1]!=-1?alpha[s1]+1:alpha[s1];
            
            if(alpha[s1] > 1) {
                res.push_back(s1);
                alpha[s1] = -1;
            }
        }
        return res; 
    }
};