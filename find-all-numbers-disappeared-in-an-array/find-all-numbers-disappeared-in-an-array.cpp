class Solution {
public:
    
    
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        vector<int> ans;
        unordered_map<int, int> exists;
        
        for(int i = 1 ; i <= nums.size(); i++) {
            exists[i] = 0;
        }
        
        for(int i = 0 ; i < nums.size(); i++) {
            exists[nums[i]] = 1;
        }
        
        for(int i = 1 ; i <= nums.size(); i++) {
            if(exists[i] == 0) {
                ans.push_back(i);
            }
        }
        
        return ans;
        
    }
};