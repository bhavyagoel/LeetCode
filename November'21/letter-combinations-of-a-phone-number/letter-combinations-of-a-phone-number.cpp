class Solution {
public:
    vector<string> res; 
    vector<string> letterCombinations(string digits) {
        unordered_map<char, vector<char>> vals; 
        vals['2'] = {'a', 'b', 'c'};
        vals['3'] = {'d', 'e', 'f'};
        vals['4'] = {'g', 'h', 'i'};
        vals['5'] = {'j', 'k', 'l'};
        vals['6'] = {'m', 'n', 'o'};
        vals['7'] = {'p', 'q', 'r', 's'};
        vals['8'] = {'t', 'u', 'v'};
        vals['9'] = {'w', 'x', 'y', 'z'};
        if (!digits.length()) return {};
        
        string temp; 
        helper(digits, temp, vals, 0);
        return res; 
    }
    
    void helper(string &digits, string &temp, unordered_map<char, vector<char>> vals, int index) {
        
        if(temp.length() == digits.length()) res.push_back(temp);
        
        for(int i = index; i < digits.length(); i++) {
            for(int j = 0; j < vals[digits[i]].size(); j++) {
                char tmp = vals[digits[i]][j];
                temp.push_back(tmp);
                helper(digits, temp, vals, i+1);
                temp.pop_back();
            }
        }
    }
};