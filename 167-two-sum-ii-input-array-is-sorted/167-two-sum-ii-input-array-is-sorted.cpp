class Solution {
public:
    vector<int> twoSum(vector<int>& num, int target) {
        
        for(int i = 0; i < num.size(); i++) {
            
            int left = target - num[i];
            
            int lo = i+1; 
            int hi = num.size()-1; 
            
            while(lo < hi) {
                int mid = (lo + hi) / 2;                 
                if(left <= num[mid]) hi = mid;
                else lo = mid+1;
            }
            
            if(left == num[lo]) return {i+1, lo+1};
            // if(left == num[hi]) return {i+1, hi+1};
        }
        
        return {0,0};
    }
};