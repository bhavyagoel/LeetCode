// Must Check Discussions for intuition, pure euclidean mathematics
// https://leetcode.com/problems/continuous-subarray-sum/discuss/150330/Math-behind-the-solutions/939374

class Solution {
public:
    bool checkSubarraySum(vector<int>& arr, int k) {
        
        unordered_map<int, int> temp;
        if(arr.size()<2) return false;
        
        int tot = 0;
        temp[0]=-1;
        for(int i = 0; i < arr.size(); i++) {
            tot+=arr[i];
            tot = k==0?tot:tot%k;

            if(temp.find(tot)!=temp.end()) {
                if ((i-temp[tot])>1) return true;
            }else {
                temp[tot]=i;
            }
        }
        return false; 
    }
};