class Solution {
public:
    vector<vector<int>> res; 
    vector<vector<int>> subsets(vector<int>& nums) {
        
        vector<int> subset; 
        subarray(nums, subset, 0);
        return res; 
        
    }
    
    void subarray(vector<int> &arr, vector<int>& subset, int index){
        
        res.push_back(subset);
        for(int i = index ; i < arr.size(); i++){
            subset.push_back(arr[i]);
            subarray(arr, subset, i+1);
            subset.pop_back();
        }
        
    }
};