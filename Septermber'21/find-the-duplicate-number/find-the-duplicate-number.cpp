// https://leetcode.com/problems/find-the-duplicate-number/discuss/560089/C%2B%2B-4-different-solutions.-(beats-100-)-Detailed-Explanantion


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