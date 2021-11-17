class Solution {
public:
    int minFlips(int a, int b, int c) {
        
        int ans = 0; 
        while(a!=0 or b!=0) {
            if ((a&1 or b&1) and !(c&1)) {
                ans += ((a&1) + (b&1));
            }
            
            if (!(a&1) and !(b&1) and (c&1)) {
                ans += 1;
            }
            
            a = a>>1;
            b = b>>1;
            c = c>>1;
        }
        while(c) {
            if(c&1) ans += 1;
            c = c>>1;
        }
        return ans;
    }
};