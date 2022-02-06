class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int num_zeros = 0;
        int n = nums.size(); 
        
        for(int i = 0 ; i < n; i++) {
            if (nums[i] == 0) {
                num_zeros++;
            }
        }
        
        for(int i = 0 ; i < n-num_zeros ; i++) {
            while(nums[i] == 0) {
                int j = i;
                while(j<n-1) {
                    nums[j] = nums[j+1];
                    j++;
                }
                nums[j] = 0;
            }
        }
    }
};