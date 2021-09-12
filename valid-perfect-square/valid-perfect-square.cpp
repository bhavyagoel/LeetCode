typedef long long int ll;

class Solution {
public:
    bool isPerfectSquare(ll num) {
        
        ll i = 1; 
        ll j = num;
        
        if(num == 1 || num == 0) {
            return true; 
        }
        
        while(i<=j) {
            ll mid = (i+j)/2;
            
            ll sq_mid = mid*mid;
            if(sq_mid == num) {
                return true; 
            }
            else if(sq_mid > num) {
                j = mid-1; 
            }
            else {
                i = mid+1;
            }
        }
        
        return false;
    }
};