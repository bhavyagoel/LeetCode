class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        
        int lo = 0; 
        int n = nums.size();
        int hi = n-1; 
        
        while(lo<hi) {
            int mid = lo + (hi-lo)/2; 
            cout<<mid<<endl;
            if(mid==0) {
                if(nums[mid]!=nums[mid+1]) return nums[mid];
                if(nums[mid]==nums[mid+1]) lo = mid+1;
                continue;
            }
            if (mid == nums.size()-1) {
                if(nums[mid]!=nums[mid-1]) return nums[mid];
                if(nums[mid]==nums[mid-1]) hi = mid; 
                continue;
            }
            if(nums[mid]!=nums[mid+1] and nums[mid]!=nums[mid-1]) return nums[mid]; 
            
            if(nums[mid]==nums[mid+1] ) {
                if((n-mid+2)%2) lo = mid+2; 
                else hi = mid;
            }
            if(nums[mid]==nums[mid-1]) {
                if ((mid-1)%2) hi = mid;
                else lo = mid+1; 
            }
        }
        
        return nums[hi]; 
    }
};