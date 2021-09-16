class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        
        vector<vector<int>> res; 
        
        int i = 1; 
        while(i <= numRows) {
            vector<int> alpha; 
            int j = 1;
            int num = 1; 
            while(j<=i) {
                alpha.push_back(num);
                num *= (i-j);
                num /= j;
                j++;
            }
            
            i++;
            res.push_back(alpha);
            
        }
        
        return res; 
    }
};