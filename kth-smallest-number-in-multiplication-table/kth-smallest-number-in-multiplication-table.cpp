class Solution {
public:
    
    bool check(int mid, int m, int n, int k) {
        int c = 0; 
        for(int i = 1; i <= m; i++) {
            c += min(n, mid/i); 
        }
        return c>=k; 
    }
    int findKthNumber(int m, int n, int k) {
        int hi = m*n; 
        int lo = 1; 
        
        while(lo<hi){
            int mid = (lo+hi)/2;
            
            if(check(mid, m, n, k)) hi = mid; 
            else lo = mid+1;
        }
        
        return lo; 
    }
};

/*
class Solution {
public:
    int findKthNumber(int m, int n, int k) {
        
        vector<int> res; 
        
        for(int i = 1 ; i <= m; i++) {
            for(int j = 1 ; j <= n; j++) {
                res.push_back(i*j);
            }
        }
        
        sort(res.begin(), res.end()); 
        
        return res[k-1];
    }
};
*/