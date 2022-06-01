class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int rot) {
        int m = grid.size(); 
        int n = grid[0].size(); 
        
        vector<int> arr(m*n, 0); 
        
        int k = 0; 
        rot = rot % (m*n); 
        
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                arr[(k + rot)%(m*n)] = grid[i][j];
                k += 1; 
            }
        }
        
        k = 0; 
        
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                grid[i][j] = arr[k++];
            }
        }
        
        return grid;
        
    }
};