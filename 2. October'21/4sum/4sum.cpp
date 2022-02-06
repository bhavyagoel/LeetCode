class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int tgt) {
        
        vector<vector<int>> res; 
        
        int n = nums.size(); 
        
        std::sort(nums.begin(), nums.end()); 
        
        for(int i = 0; i < n-1; i++) {
            for(int j = i+1; j<n; j++) {
                
                int target = tgt - (nums[i] + nums[j]);
                
                int lo = j+1; 
                int hi = n-1; 
                
                while(lo<hi) {
                    
                    int sum = nums[lo] + nums[hi];
                    // cout<<sum<<" "<<target<<endl;
                    if(sum < target) {
                        lo++;
                    }
                    
                    else if(sum > target) {
                        hi--;
                    }
                    
                    else {
                        
                        vector<int> alpha = {nums[i], nums[j], nums[lo], nums[hi]};
                        res.push_back(alpha);
                        
                        
                        while(lo<hi && alpha[2] == nums[lo]) {
                            lo++;
                        }
                        
                        while(lo<hi && alpha[3] == nums[hi]) {
                            hi--;
                        }
                        
                        while(j+1<n && nums[j+1] == alpha[1]) {
                            j++;
                        }
                        
                        while(i+1<n-1 && nums[i+1] == alpha[0]) {
                            i++;
                        }
                    }
                    
                }
            }
        }
        
        return res; 
        
    }
};