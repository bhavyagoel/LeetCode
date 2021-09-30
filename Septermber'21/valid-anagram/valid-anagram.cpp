class Solution {
public:
    bool isAnagram(string s, string t) {
        return helper(s, t);
    }
    
private:
    bool helper(string &s, string &t) {
        if(s.size() != t.size()) return false;
        
        unordered_map <char, int> first; 
        
        for(auto i : s) {
            first[i] += 1;
        }
        
        unordered_map <char, int> second; 
        for(auto i : t) {
            second[i] += 1;
        }
        
        for(auto i : first) {
            if(i.second != second[i.first]) {
                return false; 
            }
        }
        
        return true;
    }
};