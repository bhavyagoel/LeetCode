// https://leetcode.com/problems/minimum-moves-to-equal-array-elements/discuss/93817/It-is-a-math-question

class Solution {
public:
    int minMoves(vector<int>& nums) {
        int mn = INT_MAX; 
        int sum = 0, n = nums.size(); 
        for(int i = 0;i < n; i++) {
            sum += nums[i]; 
            mn = min(mn, nums[i]);
        }
        int tgt = sum - mn*n;
        return tgt; 
    }
};