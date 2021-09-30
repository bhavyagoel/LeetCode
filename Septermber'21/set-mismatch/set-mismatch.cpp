class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        
        
        vector<int> res; 
        int same;
        int sum = 0;
        for(auto i : nums) {
            int check = abs(i); 
            sum += check;
            if(nums[check -1] > 0) {
                nums[check -1] = (-1) * nums[check -1];
            }
            else {
                same = abs(i); 
            }
        }
        
        
        int n = nums.size(); 
        int total = (n*(n+1))/2;
        int missing = total - (sum - same); 
        
        res.push_back(same);
        res.push_back(abs(missing));
        
        return res; 
        
    }
};