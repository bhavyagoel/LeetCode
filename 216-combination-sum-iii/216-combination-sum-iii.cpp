class Solution {
public:
    vector<vector<int>> res; 
    void helper(int k, int n, vector<int>temp, int sum, int idx) {
        if(temp.size()==k and sum==n) {
            res.push_back(temp);
            return;
        }
        
        
        for(int i = idx; i <= 9; i++) {
            if(sum+i <= n) {
                temp.push_back(i); 
                helper(k, n, temp, sum+i, i+1);
                temp.pop_back(); 
            }
        }
        return; 
    }
    
    
    vector<vector<int>> combinationSum3(int k, int n) {
        helper(k, n, {}, 0, 1);
        return res; 
        
    }
};