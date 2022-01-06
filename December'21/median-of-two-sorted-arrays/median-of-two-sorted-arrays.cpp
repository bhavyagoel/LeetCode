class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        
        int m = nums1.size(); 
        int n = nums2.size(); 
        
        
        int mid = (m+n)/2;
        
        int j=0,k=0;
        double prev;
        double curr;
        
        for(int i = 0 ; i <= mid; i++) {
            prev = curr; 
            
            if(j!=m and k!=n) {
                curr=nums1[j]<nums2[k]?nums1[j++]:nums2[k++];
            }
            else if(j<m) {
                curr=nums1[j++];
            }else {
                curr=nums2[k++];
            }
        }
        

        return (m+n)%2?curr:(curr+prev)/2.0;
    }    
};