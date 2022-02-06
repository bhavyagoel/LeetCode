class Solution {
public:
    void solve(vector<vector<char>>& board) {
        int m = board.size(); 
        int n = board[0].size(); 
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(!visited[i][j] and board[i][j]=='O'){
                    bfs(board, visited, i, j);
                }
            }
        }
        
        return;
        
    }
    
private:
    void bfs(vector<vector<char>>& board, vector<vector<bool>>& visited, int x, int y) {
        int m = board.size(); 
        int n = board[0].size(); 
        
        queue<pair<int, int>> temp; 
        vector<pair<int, int>> check;
        
        temp.push({x,y});
        check.push_back({x,y});
        bool isBorder = false;
        while(!temp.empty()){
            int currSize = temp.size(); 
            
            while(currSize--) {
                x = temp.front().first; 
                y =  temp.front().second; 
                temp.pop(); 
                
                if(x==0 or x==m-1 or y==0 or y==n-1) isBorder = true;
                
                // Up
                if(y>0 and board[x][y-1]=='O' and !visited[x][y-1]){
                    temp.push({x, y-1});
                    check.push_back({x, y-1});
                    visited[x][y-1] = true;
                }
                
                // Left
                if(x>0 and board[x-1][y]=='O' and !visited[x-1][y]) {
                    temp.push({x-1, y});
                    check.push_back({x-1, y});
                    visited[x-1][y] = true;
                }
                
                // Right
                if(x<m-1 and board[x+1][y]=='O' and !visited[x+1][y]) {
                    temp.push({x+1, y});
                    check.push_back({x+1, y});
                    visited[x+1][y] = true;
                }
                
                // Down
                if(y<n-1 and board[x][y+1]=='O' and !visited[x][y+1]) {
                    temp.push({x, y+1});
                    check.push_back({x, y+1});
                    visited[x][y+1] = true;
                }
                
            }
            
        }
        
        if(!isBorder) {
            for(auto it : check){
                board[it.first][it.second] = 'X';
            }
        }
        
        return;
        
    }
};