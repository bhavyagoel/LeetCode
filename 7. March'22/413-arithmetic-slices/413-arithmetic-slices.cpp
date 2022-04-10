class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        if(nums.size() < 3)
            return 0;
        
        int cnt = 0, diff = 0 , ind = 0;
        int prev_diff = nums[1] - nums[0];
        
        for(int i = 1; i<nums.size()-1 ; ++i)
        {
            int diff = nums[i+1] - nums[i];
            
            if(diff ==  prev_diff)
                ++ind;
            
            else
            {
                prev_diff = diff;
                ind = 0; 
            }            
                cnt += ind;
        }
        
        return cnt;
    }
};
