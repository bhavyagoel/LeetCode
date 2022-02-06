class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
        int mx = INT_MIN;
        int n = nums.size(); 
        
        int sum = 0; 
        for(int i = 0; i < n; i++) {
            sum += nums[i];
            if(mx < sum) {
                mx = sum;
            }
            if(sum<0) {
                sum = 0;
            }
        }
        
        int mn = INT_MAX;
        sum = 0; 
        for(int i = 0 ; i < n; i++) {
            sum += nums[i];
            if(mn>sum) {
                mn = sum;
            }
            if(sum>0) {
                sum=0;
            }
        }
        
        return mx>abs(mn)?mx:abs(mn); 
    }
};