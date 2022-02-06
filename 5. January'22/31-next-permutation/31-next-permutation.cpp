class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        // Find the decreasing number from end, then swap it with the number just larger than the same
        // After that reverse the elements on the right
        
        int i = nums.size() - 2 ; 
        while(i>=0 and nums[i]>=nums[i+1]) i--;
        
        if(i >= 0) {
            int j = nums.size() -1;
            while(nums[j] <= nums[i]) {
                j--;
            }
            swap(nums[i], nums[j]);
        }
        
        reverse(nums, i+1);
    }
private:
    void reverse(vector<int> &nums, int start) {
        int end = nums.size() -1 ; 
        while(start<=end) {
            swap(nums[start], nums[end]);
            start++;
            end--;
        }
    }
};