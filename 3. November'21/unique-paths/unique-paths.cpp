#define ll long long int

class Solution {
public:
    ll uniquePaths(ll m, ll n) {
        
        ll arr[m+1][n+1];
        arr[0][0] = 1;
        for(ll i = 1 ; i < m+1; i++) {
            arr[i][0] = 1;
            ll sum = arr[i][0];
            for(ll j = 1 ; j < n+1; j++) {
                arr[0][j] = 1;
                
                sum += arr[i-1][j];
                arr[i][j] = sum;
                
            }
        }
        return arr[m-1][n-1];
    }
};