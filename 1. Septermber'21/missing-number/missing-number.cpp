class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int sum = 0;
        int AP_Sum;
        
        int n = nums.size(); 
        
        for(int i = 0 ; i < n ; i++) {
            sum += nums[i];
        }
        
        AP_Sum = (n*(n+1))/2;
        
        return AP_Sum - sum;
    }
};