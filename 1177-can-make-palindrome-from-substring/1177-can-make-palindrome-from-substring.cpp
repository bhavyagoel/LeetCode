class Solution {
public:
    vector<bool> canMakePaliQueries(string s, vector<vector<int>>& q) {
        
        vector<bool> res; 
        vector<int> temp; 
        int pos = 0; 
        temp.push_back(0); 
        
        for(int i = 0; i < s.size(); i++) {
            pos ^= 1<<(s[i]-'a');
            temp.push_back(pos);
        }
        for(int i = 0; i < q.size(); i++) {
            int left = q[i][0]; 
            int right = q[i][1]; 
            int k = q[i][2]; 
            
            int num = temp[left]^temp[right+1];
            if(k >= __builtin_popcount(num)/2) res.push_back(true);
            else res.push_back(false);
            
        }
        return res;
        
    }
};