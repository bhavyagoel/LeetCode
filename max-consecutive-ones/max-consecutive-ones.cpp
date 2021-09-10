class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        
        int n = nums.size(); 
        
        int max = INT_MIN; 
        int sum = 0;
        for(int i = 0 ; i < n ; i++) {
            sum += nums[i];
            
            if (max < sum) {
                max = sum;
            }
            if(nums[i] == 0) {
                sum = 0;
            }
        }
        
        return max; 
    }
};