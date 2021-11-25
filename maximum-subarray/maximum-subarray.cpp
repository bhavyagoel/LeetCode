class Solution {
public:
    int maxSubArray(vector<int>& arr) {
        
        int n = arr.size(); 
        int max = INT_MIN;
        int sum = 0;
        for(int i = 0 ; i < n ; i++) {
            sum += arr[i];
            
            if (max<sum){
                max = sum; 
            }
            if (sum < 0) {
                sum = 0;
            }
        }
        return max;
    }
};