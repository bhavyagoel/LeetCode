class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<int> temp; 
        helper(1, temp, n, k);
        return res; 
    }
    
    vector<vector<int>> res; 
    
    void helper(int index, vector<int>& temp, int n, int k) {
        if(k == 0) {
            res.push_back(temp); 
            return;
        }
        
        for(int i = index; i <= n; i++) {
            temp.push_back(i);
            helper(i+1, temp, n, k-1);
            temp.pop_back(); 
        }
    }
};