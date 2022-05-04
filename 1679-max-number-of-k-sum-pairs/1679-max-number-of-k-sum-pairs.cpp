class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        unordered_map<int, int> temp; 
        int n = nums.size();
        int res = 0; 
        for(int i = 0; i < n; i++) {
            if(temp[k-nums[i]]) {
                temp[k-nums[i]] -= 1;
                res += 1;
            }else{
                temp[nums[i]] += 1;
            }
        }
        
        return res;
    }
};