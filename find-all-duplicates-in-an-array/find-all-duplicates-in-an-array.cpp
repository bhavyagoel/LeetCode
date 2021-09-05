class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        int n = nums.size(); 
        vector<int> ans;
        for(int i = 0 ; i < n; i++) {
            int m = abs(nums[i]) - 1;

            if (nums[m] > 0) {
                nums[m] = -nums[m];
            }
            else {
                ans.push_back(m+1);
            }
        }
                
        return ans;
    }
};