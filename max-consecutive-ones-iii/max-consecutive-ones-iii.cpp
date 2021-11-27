class Solution {
public:
    
    int longestOnes(vector<int>& nums, int k) {
        int numZeros = 0;
        int res = INT_MIN;
        int start = 0;
        int len = 0;
        for(int i = 0; i < nums.size(); i++) {
            numZeros = nums[i]?numZeros:numZeros+1;
            len++;
            while(numZeros > k){
                if(nums[start]==0) numZeros--;
                start++;
                len--;
            }
            res = max(res, len);
        }
        return res;
    }
};