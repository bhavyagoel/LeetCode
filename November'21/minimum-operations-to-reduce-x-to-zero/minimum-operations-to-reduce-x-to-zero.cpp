class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int i = 0; 
        int j = 0; 
        int res = INT_MAX;
        int n = nums.size(); 
        int sum = 0;
        int totSum = 0; 
        for(int i = 0 ; i < n; i++) {
            totSum += nums[i];
        }
        while(i<=j and i < n) {
            while(totSum-sum > x and j<n) {
                sum += nums[j];
                j++;
            }
            if (totSum-sum==x) res = min(res, n-(j-i));
            sum -= nums[i];
            i++;
            
        }
        return res==INT_MAX?-1:res;
    }
};
