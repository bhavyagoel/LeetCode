class Solution {
public:
    int mySqrt(int x) {
        return helper(x);
    }
    
private:
    int helper(int &x) {
        if(x==0) return 0;
        if(x==1) return 1;
        
        int i = 2;
        int j = x;
        
        int val = -1; 
        while(i<= j) {
            long long int mid = i + (j-i)/2;
            
            if(mid*mid == x) {
                return mid;
            }
            
            else if (mid*mid > x) {
                val = mid;
                j = mid-1;
            }
            else{
                i = mid +1;
            }
            
        }
        return val-1;
    }
};