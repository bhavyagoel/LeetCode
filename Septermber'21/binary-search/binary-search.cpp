class Solution {
public:
    int binary_search1(vector<int> nums, int left, int right, int k) {
        int mid = (left+right)/2;
        
        if(left>right) {
            return -1;
        }
        if (nums[mid] == k) {
            return mid;
        }
        
        else if (nums[mid] < k) {
            return binary_search1(nums, mid+1, right, k);
        }
        else if (nums[mid] > k) {
            return binary_search1(nums, left, mid-1, k);
        }
        return -1;
    }
    
    int search(vector<int>& nums, int target) {
        
        int n = nums.size(); 
        int val = binary_search1(nums, 0, n-1, target);
        return val;
    }
};