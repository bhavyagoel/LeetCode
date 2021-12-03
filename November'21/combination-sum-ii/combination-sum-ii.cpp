class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<int> temp; 
        helper(candidates, temp, 0, target);
        
        return res;
    }
    
    vector<vector<int>> res; 
    map<vector<int>, int> check;
    
    void helper(vector<int>& nums, vector<int> &temp, int index, int remSum) {
        
        if(remSum==0) {
            res.push_back(temp);
            return;
        }
        
        for(int i = index; i < size(nums); i++) {
            if(i > index and nums[i] == nums[i-1]) continue; 
            
            if(remSum >= nums[i]) {
                temp.push_back(nums[i]);
                helper(nums, temp, i+1, remSum-nums[i]);
                temp.pop_back(); 
            }else{
                break;
            }
        }
    }
};
