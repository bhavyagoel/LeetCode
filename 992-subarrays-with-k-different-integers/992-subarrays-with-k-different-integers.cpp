class Solution {
public:
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        
        return subarray(nums, k) - subarray(nums, k-1);
    }
    
    int subarray(vector<int>& num, int k) {
        map<int, int> count;
        
        int res = 0, start = 0;
        for(int i = 0; i < num.size(); i++) {
            if(!count[num[i]]++) k--;
            while(k<0) if(!--count[num[start++]]) k++;
            
            
            res += i - start + 1;            
        }
        
        return res;
    }
};