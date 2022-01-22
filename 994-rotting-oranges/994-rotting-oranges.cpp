class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        
        if(grid.empty()) return -1; 
        queue<pair<int, int>> rotten; 
        int m = grid.size(); 
        int n = grid[0].size(); 
        
        int totOranges = 0; 
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(grid[i][j]==2) {
                    rotten.push(make_pair(i,j));
                }
                if(grid[i][j]==1 or grid[i][j]==2) totOranges += 1;
            }
        }
        
        int days = 0; 
        int orangesVisited = 0; 
        while(!rotten.empty()){
                
            int currSize = rotten.size(); 
            orangesVisited += currSize; 
            // cout<<currSize<<endl;
            while(currSize--) {
                pair<int, int> coord = rotten.front(); 
                int x = coord.first; 
                int y = coord.second; 
                rotten.pop(); 

                // Check left
                if(x>0 and grid[x-1][y]==1) {
                    rotten.push({x-1, y});
                    grid[x-1][y] = 2;
                }
                
                // Check right
                if(x<m-1 and grid[x+1][y]==1) {
                    rotten.push({x+1, y});
                    grid[x+1][y] = 2;
                }
                
                // Check Down
                if(y<n-1 and grid[x][y+1]==1) {
                    rotten.push({x, y+1});
                    grid[x][y+1] = 2;
                }
                
                // Check up
                if(y>0 and grid[x][y-1]==1) {
                    rotten.push({x, y-1});
                    grid[x][y-1] = 2;
                } 
            }
            
            if(!rotten.empty()) days++;
        }
        
        if(orangesVisited != totOranges) return -1; 
        return days;
    }
};