class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int i=0, prod=1, res=0, start=0;
        while(i<nums.size()) {
            if (i==nums.size()) break;
            prod *= nums[i];
            while(prod>=k) {
                if(start==nums.size()) break;
                prod /= nums[start++];
            }
            
            res += i-start+1;
            i++;
        }        
        return res>0?res:0;;  
    }
};