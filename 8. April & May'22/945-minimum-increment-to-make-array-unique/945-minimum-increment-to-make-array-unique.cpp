class Solution {
public:
    int minIncrementForUnique(vector<int>& nums) {
        
        int cnt = 0; 
        int res = 0; 
        
        sort(nums.begin(), nums.end()); 
        for(auto &it : nums) {
            if(cnt<=it) cnt = it;
            res += (cnt-it); 
            cnt++;
        }
        
        return res; 
    }
};