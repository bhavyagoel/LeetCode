class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        stack<int> temp; 
        int n = nums.size(); 
        vector<int> res(n);
        
        for(int i=n-1; i > -1;i--) {
            temp.push(nums[i]);
        }
        
        for(int i = n-1; i>-1;i--) {
            while(!temp.empty()) {
                if(temp.top()>nums[i]) break;
                temp.pop();
            }
            res[i] = temp.empty()?-1:temp.top();
            temp.push(nums[i]);
        }
                
        return res;
    }
        
};