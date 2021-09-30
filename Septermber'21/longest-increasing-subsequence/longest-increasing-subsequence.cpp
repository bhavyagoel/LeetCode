class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        
        int n = nums.size(); 

        
        vector<int> lastMax(n);
        
        for(auto &i : lastMax) {
            i = INT_MAX;
        }

        for(int i = 0 ; i < n; i++) {
            for(int j = 0 ; j < n; j++) {
                if (nums[i] <= lastMax[j]) {
                    lastMax[j] = nums[i];
                    break;
                }
            }
        }
        
        int count = 0;
        for(auto i : lastMax) {
            if(i != INT_MAX) {
                count++;
            }
        }
        
        return count;
    }
};