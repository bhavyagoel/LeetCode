class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        for(auto i : nums) {
            int checkIndex = abs(i);
            
            if(nums[checkIndex-1] > 0) {
                nums[checkIndex-1] = nums[checkIndex-1] * (-1);
            }
            else {
                return abs(i);
            }
        }
        
        return 0;
    }
};