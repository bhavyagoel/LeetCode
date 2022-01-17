class Solution {
public:
    int getMinSwaps(string nums, int k) {

        string numsCopy = nums;

        while(k--) {
            int i = nums.size() - 2; 
            // Search from last to find the decreasing number
            while(i>=0 and nums[i]>=nums[i+1]) i--;

            if(i >= 0) {
                int j = nums.size() -1;
                // Once the decreasing number is found swap it with the immediate larger number to it on the right
                // and reverse rest of the string
                
                while(nums[j] <= nums[i]) {
                    j--;
                }
                swap(nums[i], nums[j]);
            }

            reverse(nums, i+1);
        }
        
        int res = 0;
        int n = nums.length();
        for(int i = 0; i < n; i++) {
            
            if(nums[i] != numsCopy[i]) {
                int j = i; 
                // Checking when the same exits, and swapping till it reaches the same position
                while(j<n and nums[j]!=numsCopy[i]) j++;
                
                while(i<j) {
                    res++;
                    swap(nums[j], nums[j-1]);
                    j--;
                }
            }
        }

        return res;
    }
    
private:
    void reverse(string& nums, int start) {
        int end = nums.size() -1 ; 
        while(start<=end) {
            swap(nums[start], nums[end]);
            start++;
            end--;
        }
    }
};