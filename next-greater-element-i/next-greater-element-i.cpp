class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        
        
        map<int, int> alpha; 
        for(int i = 0 ; i < nums2.size(); i++){
            alpha[nums2[i]] = i;
        }
        
        vector<int> dp(nums2.size());
        dp[nums2.size()-1] = -1;
        for(int i = nums2.size()-2; i>-1; i--){
            if(nums2[i+1] > nums2[i]){
                dp[i] = nums2[i+1];
            }
            else{
                int j = i+1; 
                while(dp[j]!=-1 && dp[j]<nums2[i]){
                    j = alpha[dp[j]];
                }
                dp[i] = dp[j];
            }            
        }
        
        vector<int> res(nums1.size());
        
        for(int i = 0 ; i < nums1.size(); i++){
            res[i] = dp[alpha[nums1[i]]];
        }
        
        return res;
        
    }
};