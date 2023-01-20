class Solution {
public:
    
    set<vector<int>> res; 
    void dfs(vector<int> &nums, vector<int>& curr, int idx){
        if(idx >= nums.size()){
            if(curr.size()>=2)
                res.insert(curr);
            return;
        }
        
        // for(int i = idx; i < nums.size(); i++){
            if(curr.empty() or curr.back()<=nums[idx]) {
                curr.push_back(nums[idx]);
                dfs(nums, curr, idx+1);
                curr.pop_back();
            }
            dfs(nums, curr, idx+1);
            
        // }
        return;
    }
    
    
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        vector<int> curr; 
        int idx = 0; 
        dfs(nums, curr, idx);
        return vector(res.begin(), res.end()); 
    }
};