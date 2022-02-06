class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        map<int, int> check; 
        
        
        int n = nums.size(); 
        // if(n ==1) {
        //     return false;
        // }
        for(int i = 0 ; i < n; i++) {
            // cout<<nums[i]<<" "<<check[nums[i]]<<endl;
            if(check[nums[i]] != 0) {
                if (abs(i - check[nums[i]] + 1) <= k) {
                    return true;
                }
            } 
            check[nums[i]] = i+1;
            
            
        }
        
        return false;
    }
};