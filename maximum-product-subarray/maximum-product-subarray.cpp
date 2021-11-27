class Solution {
public:
    int maxProduct(vector<int>& nums) {

        int n = nums.size(); 
        int l = 1, r=1;
        int res = INT_MIN;
        for(int i = 0; i < n; i++) {
            l = (l?l:1)*nums[i];
            r = (r?r:1)*nums[n-i-1];
            res = max(res, l);
            res = max(res, r);
        }
        
        return res;
        
    }
};