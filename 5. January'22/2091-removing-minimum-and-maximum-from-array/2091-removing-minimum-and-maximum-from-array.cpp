class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        
        if(nums.size()<3) return nums.size(); 
        
        int mx = INT_MIN; 
        int mn = INT_MAX;
        
        int mxInd = -1; 
        int mnInd = -1; 
        int n = nums.size();
        for(int i = 0; i < n; i++) {
            if(mx<nums[i]) {
                mx = nums[i]; 
                mxInd = i;
            }
            if(mn>nums[i]) {
                mn = nums[i]; 
                mnInd = i;
            }
        }
        int bothEnd = mxInd>mnInd?((n-mxInd) + (mnInd+1)):((n-mnInd) + (mxInd+1));
        int allFront = mxInd>mnInd?(mxInd+1):(mnInd+1);
        int allBack = mxInd>mnInd?(n-mnInd):(n-mxInd);
        
        return min(bothEnd, min(allFront, allBack));
    }
};