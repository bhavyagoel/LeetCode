class Solution {
public:
    vector<vector<int>> findFarmland(vector<vector<int>>& board) {
        int m = board.size(); 
        int n = board[0].size(); 

        
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(board[i][j]==1){
                    bfs(board, i, j);
                }
            }
        }
        
        return res;
        
    }
    
private:
    vector<vector<int>> res; 
    void bfs(vector<vector<int>>& board, int x, int y) {
        int m = board.size(); 
        int n = board[0].size(); 
        
        queue<pair<int, int>> temp; 
        vector<pair<int, int>> check;
        
        temp.push({x,y});
        check.push_back({x,y});
        board[x][y] = 0;

        while(!temp.empty()){
            int currSize = temp.size(); 
            
            while(currSize--) {
                x = temp.front().first; 
                y =  temp.front().second; 
                temp.pop(); 
                                
                // Up
                if(y>0 and board[x][y-1]==1){
                    temp.push({x, y-1});
                    check.push_back({x, y-1});
                    board[x][y-1] = 0;
                }
                
                // Left
                if(x>0 and board[x-1][y]==1) {
                    temp.push({x-1, y});
                    check.push_back({x-1, y});
                    board[x-1][y] = 0;
                }
                
                // Right
                if(x<m-1 and board[x+1][y]==1) {
                    temp.push({x+1, y});
                    check.push_back({x+1, y});
                    board[x+1][y] = 0;
                }
                
                // Down
                if(y<n-1 and board[x][y+1]==1) {
                    temp.push({x, y+1});
                    check.push_back({x, y+1});
                    board[x][y+1] = 0;
                }
                
            }
            
        }
        
        vector<int> tmp; 
        tmp.push_back(check[0].first);
        tmp.push_back(check[0].second);
        tmp.push_back(check[check.size()-1].first);
        tmp.push_back(check[check.size()-1].second);
            
        res.push_back(tmp); 
            
    
        return;
        
    }
};