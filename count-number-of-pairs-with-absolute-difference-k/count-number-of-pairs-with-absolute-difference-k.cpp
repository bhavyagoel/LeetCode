class Solution {
public:
    int countKDifference(vector<int>& nums, int k) {
        
        int count = 0;
        int n = nums.size(); 
        for(int i = 0 ; i < n-1; i++) {
            for(int j = i+1; j < n; j++) {
                if(abs(nums[i] - nums[j]) == k) {
                    count++;
                }
            }
        }
        
        
        return count;
    }
};