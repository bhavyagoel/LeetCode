class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        return helper(strs);
    }
    
private:
    string helper(vector<string>& strs) {
        
        int k = 0;
        string res = "";
        for(int k = 0; k < strs[0].size(); k++) {
            bool flag = true;
            for(int i = 1 ; i < strs.size(); i++) {
                if(strs[0][k] != strs[i][k]) {
                    flag = false;
                    break;
                }
            }
            
            if (flag) {
                res += strs[0][k];
            }
            else{
                break;
            }
        }
        
        return res;
    }
};