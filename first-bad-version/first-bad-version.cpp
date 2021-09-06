// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    
    
    int firstBadVersion(int n) {
        
        int i = 1; 
        int j = n;
        int index; 
        while(i>=j) {
            int mid = (i +j-1)/2;
            if(i==j){
                return i;
            }
            i++;
            j--;
            if (isBadVersion(mid)) {
                index = mid;
                j = mid-1; 
                i=0;
            }
            else {
                i = mid+1;
                j = n;
            }
        }
        return index;
    }
};