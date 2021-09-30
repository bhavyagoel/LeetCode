typedef long long ll; 

class Solution {
public:
    int reverse(int x) {
        ll ans = 0; 
        
        while(x) {
            int rem = x%10;
            x = x/10;
            ans *= 10;
            ans += rem;
            
            // cout<<ans<<" ";
        }
        if(ans >= INT_MAX || ans <= INT_MIN) {
            return 0;
        }
        
        return ans;
        
    }
};