class Solution {
public:
    vector<vector<int>> largeGroupPositions(string s) {
        return helper(s);
    }

private:
    vector<vector<int>> helper(string &s) {
        int n = s.size(); 
        vector<vector<int>> res;
        for(int i = 0 ; i < n-1; i++) {
            char temp = s[i];
            int start = i; 
            int end = i; 
            while(s[i+1] == temp && i<n-1) {
                end++;
                i++;
            }
            if((end-start) >= 2) {
                vector<int>alpha {start, end};
                res.push_back(alpha); 
            }
        }
        
        return res; 
    }
};