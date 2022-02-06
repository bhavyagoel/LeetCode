class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int tgt) {
        vector<vector<int>> res;
        if(nums.size()<4) return res; 
        sort(nums.begin(), nums.end());
        int n = nums.size(); 
        for(int i = 0; i < n; i++){
            int target = tgt - nums[i]; 
            vector<vector<int>> temp = threeSum(nums, i+1, target);
            
            for(auto it : temp){
                res.push_back({nums[i], it[0], it[1], it[2]});
            }
            int tmp = nums[i];
            while(i<n and tmp==nums[i]){
                i++;
            }
            i--;
        }
        
        return res;
    }
private:
    vector<vector<int>> threeSum(vector<int>& nums, int start, int tgt) {
        
        vector<vector<int>> res; 
        
        int n = nums.size();
        for(int i = start; i < n; i++) {
            
            int lo = i+1; 
            int hi = n-1; 
            int target = tgt-nums[i];
            
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