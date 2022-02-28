class Solution {
public:
    char findTheDifference(string s, string t) {
        
        int s1 = 0; 
        for(auto& it : s) {
            s1 += it;
        }
        
        int s2 = 0; 
        for(auto& it : t) {
            s2 += it;
        }
        
        return (s2-s1);
    }
};