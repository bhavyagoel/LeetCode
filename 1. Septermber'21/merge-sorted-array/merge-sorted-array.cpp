class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        helper(nums1, m, nums2, n);
    }
    
private:
    void helper(vector<int> &nums1, int &m, vector<int> &nums2, int &n) {
        
        int i = nums1.size()-1; 
        int k = i - n; 
        int j = n-1; 
        
        while(k>=0 && j>=0) {
            if (nums1[k] >= nums2[j]) {
                nums1[i--] = nums1[k--];
            }
            
            else if (nums1[k] < nums2[j]) {
                nums1[i--] = nums2[j--];
            }
        }
        
        while(k>=0) {
            nums1[i--] = nums1[k--];
        }
        
        while(j>=0) {
            nums1[i--] = nums2[j--];
        }
    }
};