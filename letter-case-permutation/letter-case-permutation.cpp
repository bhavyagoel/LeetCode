class Solution {
public:
    vector<string> letterCasePermutation(string s) {
        vector<string> res; 
        letterCase(s, res, 0);
        return res; 
    }
    
    void letterCase(string& s, vector<string>&res, int index){
        res.push_back(s);
        
        for(int i = index ; i < s.length(); i++){
            if(isalpha(s[i])) s[i] = islower(s[i])?toupper(s[i]):tolower(s[i]);
            else continue;
            
            letterCase(s, res, i+1);
            if(isalpha(s[i])) s[i] = islower(s[i])?toupper(s[i]):tolower(s[i]);
            
        }
    }
};