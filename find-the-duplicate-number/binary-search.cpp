class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        return helper(nums);
    }
    
private:
    int helper(vector<int> &nums) {
        
        int lo = 0;
        int hi = nums.size(); 
        int duplicate = -1; 
        while(lo <= hi) {
            int mid = lo + (hi - lo)/2;
            int count = getCount(nums, mid);
            
            if(count <= mid) lo = mid+1;
            else{
                duplicate = mid;
                hi = mid-1;
            } 
        }
        
        return duplicate;
    }
    
    int getCount(vector<int> &nums, int val) {
        int count = 0; 
        for(int i = 0; i < nums.size(); i++) {
            if(nums[i] <= val) {
                count++;
            }            
        }
        return count; 
        
    }
};
