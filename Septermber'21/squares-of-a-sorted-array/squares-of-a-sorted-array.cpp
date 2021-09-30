class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        
        int n = nums.size(); 
        
        map <int, int> mp;
        vector<int> ans;
        for(int i = 0 ; i < n ; i++) {
            // nums[i] = labs(nums[i]);
            int sq = pow(nums[i], 2);
            mp[sq] += 1;
        }
        
        for(auto i: mp) {
            for(int j = 0 ; j < i.second; j++){
                ans.push_back(i.first);
            }
        }
        return ans;
    }
};