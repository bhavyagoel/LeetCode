class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int i = 0; 
        int j = 0; 
        int res = INT_MAX;
        int n = nums.size(); 
        int sum = 0;
        while(i<=j and i < n) {
            while(sum < target and j<n) {
                sum += nums[j];
                j++;
            }
            if (sum>=target) res = min(res, j-i);
            sum -= nums[i];
            i++;
            
        }
        return res==INT_MAX?0:res;
    }
};