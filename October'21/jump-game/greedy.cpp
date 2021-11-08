class Solution {
public:
    // Even After Memoization the Runtime is quite bad 
    // Approach Optimised -> take a max reach element , This indicate to which position have you reached starting from i .
    // At the end check if max Reach. In this greedy would also work that you are taking the maximum jump . If in the end you are 
    // able to reach the maximum element then you can definitely take jumps from 1 -> max 
    bool canJump(vector<int>& nums) {
        int i =0;
        for( int maxReach=0; i <nums.size() &&  i <= maxReach ;i++){
            maxReach = max(i+nums[i], maxReach);
        }
        return i == nums.size();
    }
};
