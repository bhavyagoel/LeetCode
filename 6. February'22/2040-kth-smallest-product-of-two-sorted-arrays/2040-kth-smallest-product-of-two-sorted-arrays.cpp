class Solution {
public:
    long long kthSmallestProduct(vector<int>& nums1, vector<int>& nums2, long long k) {
        vector<long long> A1, A2, B1, B2; 
        
        for(auto &it : nums1) {
            if(it<0) A1.push_back(-it);
            else A2.push_back(it);
        }
        reverse(A1.begin(), A1.end()); 
        
        for(auto &it : nums2) {
            if(it<0) B1.push_back(-it);
            else B2.push_back(it); 
        }
        reverse(B1.begin(), B1.end()); 
        
        int tot_neg = A1.size()*B2.size() + A2.size()*B1.size();
        
        int sign;
        if(k>tot_neg) {
            sign = 1; 
            k -= tot_neg;
        }else{
            k = tot_neg - k + 1;
            sign = -1; 
            swap(B1, B2);
        }
        
        long long int left = 0, right = pow(10,10); 
        while(left < right) {
            long long int mid = (left + right) / 2;
            if (count(A1, B1, mid) + count(A2, B2, mid) >= k) {
                right = mid; 
            }else{
                left = mid+1;
            }
        }
        
        return left*sign;
    }
    
private:
    long long int count(vector<long long>& A, vector<long long>& B, long long int x) {
        long long int res = 0; 
        int j = B.size() - 1; 
        
        for(int i = 0; i < A.size(); i++) {
            while(j>-1 and A[i]*B[j]>x) j--;
            
            res += j+1;
        }
        return res; 
    }
};