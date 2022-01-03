class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        if(n==1) return 1; 
        vector<int> trustNone(n, 1);
        vector<vector<int>> trustedBy(n, vector<int> (n,1));
        
        int len = trust.size(); 
        
        for(int i = 0; i < len; i++) {
            int first = trust[i][0]-1;
            int sec = trust[i][1]-1;
            trustNone[first] = -1;
            trustedBy[sec][first] = -1;
        }
        int ans = -1; 
        for(int i = 0 ; i < n; i++) {
            if (trustNone[i] == 1) {
                for(int j = 0 ; j < n; j++) {
                    if (i != j) {
                        if (trustedBy[i][j] == -1) {
                            ans = i+1;
                        }else {
                            ans = -1; 
                            break;
                            
                        }
                    }
                }
            }
            
            if (ans == i+1) return i+1;
        }
        
        return ans;
    }
};