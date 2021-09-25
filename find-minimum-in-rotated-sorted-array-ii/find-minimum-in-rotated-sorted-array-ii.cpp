class Solution {
public:
    int findMin(vector<int>& nums) {
        return helper(nums);
    }
    
private:
    int helper(vector<int> &nums) {
        
        if (nums.size() == 1) return nums[0];
        if (nums.size() == 2) return min(nums[0], nums[1]);
        
        int lo = 0; 
        int hi = nums.size() -1; 
        while(lo<= hi) {
            int mid = lo + (hi - lo)/2;
            
            if(nums[hi] < nums[mid]) {
                lo = mid+1;
            }
            else if(nums[hi] > nums[mid]){
                hi = mid;
            } 
            else {
                hi--;
            }
        }
        return nums[lo];
        
    }
};