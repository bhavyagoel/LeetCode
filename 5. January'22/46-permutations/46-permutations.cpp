class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        int n = nums.size(); 
        
        // vector<bool> check(n, false);
        // vector<int> ds; 
        // helper(ds, check, nums, n);
        
        swapping(0, nums, n);
        return res; 
    }
    
private:
    vector<vector<int>> res; 
    
    void swapping(int idx, vector<int> &nums, int n) {
        if(idx==n) {
            res.push_back(nums);
            return;
        }
        
        for(int i = idx; i < n; i++) {
            swap(nums[idx], nums[i]);
            swapping(idx+1, nums, n);
            swap(nums[idx], nums[i]);
        }
        return;
    }
    
    
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