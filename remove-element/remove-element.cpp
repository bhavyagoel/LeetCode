class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
     
        
        int n = nums.size(); 
        int count = 0; 
        
        // for(int i = 0 ; i < n ; i++) {
        //     if(nums[i] == val){
        //         count++;
        //     }
        // }
        
        int j = 0;
        for(int i = 0 ; i < n ; i++) {
            if (nums[i] != val){
                nums[j] = nums[i];
                j++;
                // i--;
                count++;
            }
        }
        // cout<<n<<" "<<count;
        return count; 
    }
};