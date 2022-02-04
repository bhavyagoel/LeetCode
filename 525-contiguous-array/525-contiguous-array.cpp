class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        
        int n = nums.size(); 
         
        unordered_map<int, int> checkPrev;
        int cnt = 0; 
        int res = 0; 
        checkPrev[0] = -1;
        for(int i = 0; i < n; i++) {
            if(nums[i]==0) cnt -= 1;
            else cnt += 1;

            if(checkPrev.find(cnt) == checkPrev.end()) checkPrev[cnt] = i;
            else {
                int dist = i - checkPrev[cnt];
                res = max(res, dist);
            }
        }
        return res;
    }
};