class Solution {
public:
    int searchInsert(vector<int>& A, int target) {
        int i = 0 ; 
        int j = A.size()-1; 
        while(i<=j){
            int mid = (i+j)/2;
            if(A[mid] == target) return mid;
            else if(A[mid] > target) j = mid-1;
            else i = mid+1;
        }
        return i; 
    }
};