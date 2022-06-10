class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        // unique subarray sum 
        map<int, int> temp; 
        int init = 0, sum = 0, res = INT_MIN;
        for(int i = 0; i < nums.size(); i++) {
            temp[nums[i]]++;
            sum += nums[i];
            while(temp[nums[i]] > 1) {
                sum -= nums[init];
                temp[nums[init++]]--;
            }
            res = max(res, sum);
        }
        return res;
    }
};