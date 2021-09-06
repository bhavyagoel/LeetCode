class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        
        int n = nums.size(); 
        vector<int> ans;
        map<int, int> res;
        for(int i = 0 ; i < n ; i++) {
            res[nums[i]] = i;
        }
        
        for(int i = 0; i< n; i++) {
            int rem = target - nums[i];
            if ((res[rem] != i) && res[rem]) {
                ans.push_back(i);
                ans.push_back(res[rem]);
                break;
            }
            
        }
        
        return ans;
    }
};