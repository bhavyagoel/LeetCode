class Solution {
public:
    
    int get_count(int n) {
        int ans = 0; 
        while(n!=0) {
            int c = n&1;
            
            if (c == 1) {
                ans++;
            }
            n = n>>1;
        }
        
        return ans;
    }
    

    vector<int> countBits(int n) {
        
        vector<int> res(n+1);
        for(int i = 0; i < n+1; i++) {
            // res.push_back(get_count(i));
            res[i] = res[i>>1] + (i&1);
        }
        
        return res;
    }
    
};
