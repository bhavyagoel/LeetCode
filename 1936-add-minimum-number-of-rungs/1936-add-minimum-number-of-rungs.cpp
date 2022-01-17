class Solution {
public:
    int addRungs(vector<int>& rungs, int dist) {
        int cnt = 0; 
        int n = rungs.size();
        int diff = rungs[0]-0;
        
        if(diff%dist==0) {
            cnt += (diff/dist) - 1;
        }
        else cnt += ceil(diff/dist);
        
        for(int i = 1; i < n; i++) {
            diff = rungs[i] - rungs[i-1];
            
            if(diff>dist) {
                if(diff%dist==0) {
                    cnt += (diff/dist) - 1;
                    continue;
                }
                cnt += ceil(diff/dist);
            }
        }
        
        return cnt;
    }
};