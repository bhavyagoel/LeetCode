class Solution {
public:
    vector<int> temp; 
    Solution(vector<int>& nums) {
        temp = nums;
    }
    
    int pick(int target) {
        int count = 0; 
        int idx;
        for(int i = 0; i < temp.size(); i++) {
            if (temp[i] == target){
                count++;
                
                if (rand() % count == 0) {
                    idx = i;
                }
            }
        }
        return idx;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * int param_1 = obj->pick(target);
 */