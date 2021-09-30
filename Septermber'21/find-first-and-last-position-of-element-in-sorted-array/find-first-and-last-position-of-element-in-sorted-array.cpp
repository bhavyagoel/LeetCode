class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        
        int i = 0; 
        int j = nums.size() - 1;
        int n = nums.size();
        vector<int> ans = {-1, -1};
        
        while(i <= j) {
            int mid = i + (j-i)/2;
            if(nums[mid] == target) {
                ans[0] = mid;
                ans[1] = mid;
                int k = mid-1;
                while(k>-1 && nums[k]==target) {
                    ans[0] = k;
                    k--;
                }
                k = mid+1;
                while(k<n && nums[k]==target) {
                    ans[1] = k;
                    k++;
                }
                break;
            }
            
            else if (nums[mid] > target) {
                j = mid-1;
            }
            
            else if (nums[mid] < target) {
                i = mid+1;
            }
        }
        return ans;
    }
};