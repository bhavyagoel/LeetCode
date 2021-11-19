class Solution {
public:
    int dp[1000];
    int minSteps(int n) {
        // if(n==1) return 0; 
        // if(n==2) return 2;
        // if(n==3) return 3; 
        int prims[] = {2,3,5,7,11,13,17,19,23,29,31};
        if (n < 6) return n == 1 ? 0 : n;
        for(auto i : prims){
            if (!(n%i)) return i + minSteps(n/i);
        }
        
        return n;
    }
};