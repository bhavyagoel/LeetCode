class Solution {
public:
    int climbStairs(int n) {
        /*
        if(n==0) return 1; 
        if(n==1) return 1; 
        
        int left = climbStairs(n-1); 
        int right = climbStairs(n-2); 
        
        return left + right;
        */
        
        int prev2 = 1; 
        int prev = 1; 
        for(int i = 2; i <= n; i++) {
            int curri = prev + prev2;
            prev2 = prev; 
            prev = curri;
        }
        return prev; 
    }
};