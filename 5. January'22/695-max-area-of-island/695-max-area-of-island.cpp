class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int m = grid.size(); 
        int n = grid[0].size(); 
        int res = 0; 
        
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(grid[i][j]==1){
                    res = max(res, getArea(grid, i, j));
                }
            }
        }
        
        return res;
    }
    
private:
    
    int getArea(vector<vector<int>>& grid, int x, int y) {
        int m = grid.size(); 
        int n = grid[0].size(); 
        
        queue<pair<int, int>> temp; 
        temp.push({x,y});
        grid[x][y] = 0;
        int area = 0; 
        while(!temp.empty()){
            int currSize = temp.size(); 
            area += currSize; 
            
            while(currSize--) {
                
                x = temp.front().first; 
                y = temp.front().second; 
                temp.pop(); 
                
                // Up
                if(y>0 and grid[x][y-1]==1){
                    temp.push({x, y-1});
                    grid[x][y-1] = 0;
                }
                
                // Left
                if(x>0 and grid[x-1][y]==1) {
                    temp.push({x-1, y});
                    grid[x-1][y] = 0;
                }
                
                // Right
                if(x<m-1 and grid[x+1][y]==1) {
                    temp.push({x+1, y});
                    grid[x+1][y] = 0;
                }
                
                // Down
                if(y<n-1 and grid[x][y+1]==1) {
                    temp.push({x, y+1});
                    grid[x][y+1] = 0;
                }
            }
        }
        
        return area; 
    }
};