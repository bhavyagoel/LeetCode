class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        int n = nums.size(); 
        sort(nums.begin(), nums.end()); 
        vector<int> ds; 
        subset(ds, 0, nums, n);
        return res; 
    }
    
private:
    vector<vector<int>> res; 
    map<vector<int>, bool> temp; 
    void subset(vector<int>& ds, int idx, vector<int>& nums, int n) {
        
        if(!temp[ds]) {
            res.push_back(ds);
            temp[ds] = true;
        }
        
        for(int i = idx; i < n; i++) {
            // if(i>idx and nums[i]==nums[i-1]) continue;
            ds.push_back(nums[i]);
            subset(ds, i+1, nums, n);
            ds.pop_back(); 
        }
        
        return;
        
    }
    
};