class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> temp; 
        helper(candidates, temp, 0, target);
        return res;
    }
    
    vector<vector<int>> res; 
    
    void helper(vector<int>& nums, vector<int> &temp, int index, int remSum) {
        
        if(remSum==0) res.push_back(temp);
        
        for(int i = index; i < size(nums); i++) {
            temp.push_back(nums[i]);
            if(remSum >= nums[i]) helper(nums, temp, i, remSum-nums[i]);
            temp.pop_back(); 
        }
    }
};