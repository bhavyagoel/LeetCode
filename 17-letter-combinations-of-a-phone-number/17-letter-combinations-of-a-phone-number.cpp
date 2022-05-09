class Solution {
public:
    vector<string> res; 
    unordered_map<char, string> dig; 
    vector<string> letterCombinations(string digits) {
        if(digits.size()==0) return {}; 
        dig['1'] = "";
        dig['2'] = "abc";
        dig['3'] = "def";
        dig['4'] = "ghi";
        dig['5'] = "jkl";
        dig['6'] = "mno";
        dig['7'] = "pqrs";
        dig['8'] = "tuv";
        dig['9'] = "wxyz";
        
        helper(digits, 0, digits.size(), "");
        return res; 
    }
    
    
    void helper(string d, int pos, int n, string temp) {
        if(pos==n) {
            res.push_back(temp);
            return;
        }
        
        string tmp = dig[d[pos]];
        for(int i = 0; i < tmp.size(); i++) {
            temp.push_back(tmp[i]);
            helper(d, pos+1, n, temp);
            temp.pop_back(); 
        }
    }
};