class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        int n = nums.size(); 
        
        permute(0, nums, n);
        return res; 
    }

private:
    vector<vector<int>> res; 
   
    void permute(int idx, vector<int> &nums, int n) {
        if(idx==n) {
            res.emplace_back(nums);
            return;
        }
        
        unordered_map<int, bool> check;
        for(int i = idx; i < n; i++) {
            if(check[nums[i]]) continue;
            
            check[nums[i]] = true;
            swap(nums[idx], nums[i]);
            permute(idx+1, nums, n);
            swap(nums[idx], nums[i]); 
            
        }
        return;
    }
    
};