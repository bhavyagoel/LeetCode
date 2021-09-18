class Solution {
public:
    int countKDifference(vector<int>& nums, int k) {
        int n = nums.size();         
        
        // Using map
        
        unordered_map <int, int> alpha; 
        int count = 0 ; 
        for(int i = 0 ; i < n; i++) {
            count+= alpha[nums[i] - k];
            count+= alpha[nums[i] + k];
            alpha[nums[i]]++;
        }
        
        
        // int count = 0;
        // for(int i = 0 ; i < n-1; i++) {
        //     for(int j = i+1; j < n; j++) {
        //         if(abs(nums[i] - nums[j]) == k) {
        //             count++;
        //         }
        //     }
        // }
        return count;
    }
};