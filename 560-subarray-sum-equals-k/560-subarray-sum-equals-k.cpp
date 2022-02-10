class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> temp; 
        int n = nums.size(); 
        
        temp[0]++;
        
        int sum = 0; 
        int res = 0;
        
        for(int i = 0; i < n; i++) {
            sum += nums[i];
            res+=temp[sum-k];
            temp[sum]++;
        }
        return res;
    }
};