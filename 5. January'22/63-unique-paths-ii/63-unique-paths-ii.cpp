class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& g) {
        int m = g.size(); 
        int n = g[0].size(); 
        
        vector<vector<int>> arr(m+1, vector<int>(n+1,0));
        arr[0][0] = 1;
        arr[0][1] = 1;

        for(int i = 1; i <= m; i++) {
            arr[i-1][0] = 0;
            for(int j = 1 ; j <= n; j++) {
                arr[0][j-1]= 0;
                
                if(g[i-1][j-1]==1) {
                    arr[i][j] = 0;
                    continue;
                }
                
                arr[i][j] = arr[i][j-1]+arr[i-1][j];
            }
        }
        
        return arr[m][n];
    }
};