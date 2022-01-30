class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        
        for(int i = 0; i < abs(n-k%n); i++){
            nums.push_back(nums[i]);
        }

        /*
        for(int i = 0; i < abs(n-k%n); i++){
            nums.erase(nums.begin());
        }
        */
        
        for(int i = 0; i < n; i++){
            nums[i] = nums[i + abs(n-k%n)];
        }
        
        int val = abs(n-k%n);
        while(val){
            nums.pop_back();
            val--;
        }
    }
};