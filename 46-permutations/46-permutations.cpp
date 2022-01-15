class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        int n = nums.size(); 
        vector<bool> check(n, false);
        vector<int> ds; 
        
        helper(ds, check, nums, n);
        return res; 
    }
    
private:
    vector<vector<int>> res; 
    
    void helper(vector<int> &ds, vector<bool> check, vector<int>& nums, int n) {
        
        if (ds.size()==n) {
            res.push_back(ds);
            return; 
        }
        
        for(int i = 0 ; i < n; i++) {
            if(!check[i]) {
                check[i]=true; 
                ds.push_back(nums[i]);
                helper(ds, check, nums, n);
                check[i]=false; 
                ds.pop_back(); 
            }
        }
        
    }
};