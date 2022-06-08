class Solution {
public:
    int removePalindromeSub(string s) {
        bool flag = true;
        for(int i = 0, j = s.size()-1; i < s.size()/2, j >=s.size()/2; i++, j--) {
            if(s[i]!= s[j]){
                flag = false;
                break;
            }
        }
        
        return flag?1:2;
    }
};