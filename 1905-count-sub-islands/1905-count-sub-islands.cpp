class Solution {
public:
    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        int m = grid1.size(); 
        int n = grid1[0].size(); 
        int res = 0; 
        
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(grid2[i][j]==1){
                    if (getArea(grid1, grid2, i, j)) { 
                        res += 1;
                    }
                }
            }
        }
        
        return res;
    }
private:
    bool getArea(vector<vector<int>>& grid1, vector<vector<int>>& grid2, int x, int y) {
        int m = grid2.size(); 
        int n = grid2[0].size(); 
        
        queue<pair<int, int>> temp; 
        temp.push({x,y});
        grid2[x][y] = 0;
        bool ans = true;
        while(!temp.empty()){
            int currSize = temp.size();             
            while(currSize--) {
                
                x = temp.front().first; 
                y = temp.front().second; 
                temp.pop(); 
                if(grid1[x][y]==0) ans = false;
                // Up
                if(y>0 and grid2[x][y-1]==1){
                    temp.push({x, y-1});
                    grid2[x][y-1] = 0;
                }
                
                // Left
                if(x>0 and grid2[x-1][y]==1) {
                    temp.push({x-1, y});
                    grid2[x-1][y] = 0;
                }
                
                // Right
                if(x<m-1 and grid2[x+1][y]==1) {
                    temp.push({x+1, y});
                    grid2[x+1][y] = 0;
                }
                
                // Down
                if(y<n-1 and grid2[x][y+1]==1) {
                    temp.push({x, y+1});
                    grid2[x][y+1] = 0;
                }
            }
        }
        return ans;
    }
};

