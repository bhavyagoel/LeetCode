class Solution {
public:
    int count = 0; 
    int countMaxOrSubsets(vector<int>& nums) {
        int mxOR = 0; 
        for(int i = 0; i < nums.size(); i++){
            mxOR |= nums[i];
        }
        vector<int> subset; 
        findMax(nums, subset, 0, mxOR, 0);
        
        
        return count;
    }
    
    void findMax(vector<int> &nums, vector<int>&subset, int index, int mxOR, int temp){

        if(temp == mxOR) count++;
        
        for(int i = index; i < nums.size(); i++){
            subset.push_back(nums[i]);
            findMax(nums, subset, i+1, mxOR, temp | nums[i]);
            subset.pop_back();
        }
    }
};