class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        map<int, bool> check; 
        
        
        for(auto it : nums) {
            check[it] = true; 
        }
        
        
        int res = 0; 
        for(auto it : check) {
            if(!check[it.first-1]) {
                int curr = it.first; 
                int len = 1; 
                while(check[++curr]) {
                    ++len; 
                }
                
                res = max(res, len); 
            }
        }
        
        return res; 
    }
};