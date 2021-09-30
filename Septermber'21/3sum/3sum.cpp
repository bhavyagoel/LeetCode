class Solution {
public:    
    vector<vector<int>> threeSum(vector<int>& nums) {
        
        vector<vector<int>> res; 
        
        std::sort(nums.begin(), nums.end());
        int n = nums.size();
        for(int i = 0 ; i < n; i++) {
            
            int lo = i+1; 
            int hi = n-1; 
            int target = -nums[i];
            
            while(lo<hi) {
                int sum = nums[lo] + nums[hi];
                
                if(sum > target) {
                    hi--;
                }
                else if (sum < target) {
                    lo++;
                }
                else {
                    vector <int> alpha = {nums[i], nums[lo], nums[hi]};
                    res.push_back(alpha);
                
                
                    while(lo<hi && nums[lo] == alpha[1]) {
                        lo++;
                    }

                    while(lo<hi && nums[hi] == alpha[2]) {
                        hi--;
                    }

                    while(i+1<n && nums[i+1] == alpha[0]) {
                        i++;
                    }
                }
            }
        }
        
        return res;
    }
};