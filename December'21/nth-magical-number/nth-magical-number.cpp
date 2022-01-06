class Solution {
public:
    long modulo = 7 + 1e9;
    int nthMagicalNumber(long n, long a, long b) {
        // To tell total number of divisible number before x, we do x/a+x/b (if !x%a or !x%b)
        // For common numbers diivisble by a and b are, a*b
        // So total number divible by either a or b before x are {x/a + x/b - x/a*b}
        
        if(n==1) return min(a,b);
                
        long lo = min(a,b);
        long hi = n*min(a,b);
        long ab = a*b/ __gcd(a,b);       
        
        while(lo<hi) {
            long mid = lo + (hi-lo)/2; 
            
            // If either of a and b is a multiple of other
            long prevDivisible = mid/a + mid/b - mid/ab; 
            
            if (prevDivisible<n) lo = mid + 1;
            else hi = mid;
        }
        return lo%modulo;
    }
};