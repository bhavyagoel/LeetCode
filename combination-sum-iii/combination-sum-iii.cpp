class Solution {
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int> temp; 
        helper(1, temp, n, k);
        return res; 
    }
    
    vector<vector<int>> res; 
    
    void helper(int index, vector<int> &temp, int n, int k) {
        
        if(temp.size() == k and n==0) res.push_back(temp);
        
        for(int i = index; i < 10; i++) {
            if(n >= i) {
                temp.push_back(i);
                helper(i+1, temp, n-i, k);
                temp.pop_back(); 
            }else {
                break;
            }
        }
    }
};