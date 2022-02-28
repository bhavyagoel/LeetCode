class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> res; 
        int n = nums.size();
        
        for(int i = 0; i < n; i++) {
            string temp = ""; 
            int start = i;
            while(i+1 < n and (nums[i] + 1) == nums[i+1]) i += 1;
            int end = i; 
            if(start==end) temp = to_string(nums[start]);
            else temp = to_string(nums[start])+"->"+to_string(nums[end]);
            
            res.push_back(temp); 
        
        }
        
        return res; 
    }
};