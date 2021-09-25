class Solution {
public:
    int findMin(vector<int>& nums) {
        return helper(nums);
    }

private:
    int helper(vector<int> &nums) {
        int lo = 0; 
        int hi = nums.size() -1; 
        int min = nums[0];
        while(lo<= hi) {
            int mid = lo + (hi - lo)/2;
            
            if(nums[mid] < min) {
                min = nums[mid];
                hi = mid-1;
            }
            else {
                lo = mid+1;
            }
        }
        
        return min;
    }
};