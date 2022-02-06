class Solution {
public:
    int nthUglyNumber(int n) {
        
        vector<int> res(n); 
        
        res[0] = 1; 
        int t2 = 0; 
        int t3 = 0; 
        int t5 = 0; 
        
        for(int i = 1 ; i < n; i++) {
            res[i] = min(res[t2]*2, min(res[t3]*3, res[t5]*5));
            if(res[i] == res[t2]*2) t2++;
            if(res[i] == res[t3]*3) t3++;
            if(res[i] == res[t5]*5) t5++;
        }
        
        return res[n-1];
    }
};