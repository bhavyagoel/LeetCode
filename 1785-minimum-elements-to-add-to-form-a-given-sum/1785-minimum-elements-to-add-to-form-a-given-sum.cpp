class Solution {
public:
    int minElements(vector<int>& nums, int limit, int goal) {
        long long int tot = 0; 
        for(auto i : nums) {
            tot += i; 
        }
        tot = abs(goal-tot);
        return (tot+limit-1)/limit;
    }
};