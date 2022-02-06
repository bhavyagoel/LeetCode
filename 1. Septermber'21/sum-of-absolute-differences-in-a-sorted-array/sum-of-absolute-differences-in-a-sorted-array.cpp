class Solution {
public:
     
    vector<int> getSumAbsoluteDifferences(vector<int>& arr) {
        int n = arr.size();
        vector <int> ans(arr.size(), 0);
        int sum = 0; 
        
        for(int i= 0 ; i < n; i++) {
            sum+= arr[i];
        }
        int rsum = 0;
        for(int i = 0 ; i < n; i++) {            
            int num = (arr[i]*i - rsum) + (sum - arr[i]*(n-i));
            
            ans[i] = num;
            rsum+= arr[i];
            sum-= arr[i];
        }
        return ans;
    }
};