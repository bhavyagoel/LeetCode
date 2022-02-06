class Solution {
public:
    
    
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        vector<int> ans;

        int n = nums.size(); 
        for(int i = 1; i <= n; i++) {
            ans.push_back(i);
        }
        
        for(int i = 0 ; i < n ; i++) {
            ans[nums[i]-1] = 0;    
        }
        
        int j = 0;
        for(int i = 0 ; i < n ; i++) {
            if (ans[i] != 0) {
                swap(ans[j], ans[i]);
                j++;
            }
        }
        
        for(int i = n-1 ; i >= 0; i--) {
            if(ans[i] == 0) {
                ans.pop_back();
            }
        }    
        
        return ans;
        
    }
};
