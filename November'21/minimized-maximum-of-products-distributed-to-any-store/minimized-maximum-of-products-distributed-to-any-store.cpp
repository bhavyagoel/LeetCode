class Solution {
public:
    
    int canDist(vector<int> q, int quant) {
        int res = 0; 
        
        for(int i = 0; i < q.size(); i++) {
            while(q[i]>0) {
                q[i]-=quant; 
                res++;
            }
        }
        
        return res; 
    }    
    
    int minimizedMaximum(int n, vector<int>& q) {
        int hi = INT_MAX; 
        for(int i = 0; i < q.size(); i++) {
            hi = max(q[i], hi);
        }
        int lo = 1; 
        while(lo<hi) {
            int mid = lo + (hi-lo)/2; 
            int cnt = canDist(q, mid); 
            
            if(cnt>n) lo = mid+1; 
            else hi = mid; 
            
        }
        
        return lo;
    }
};