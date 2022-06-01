class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        int m = board.size(); 
        int n = board[0].size(); 
        map<pair<int, int>, int> temp; 
        
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                int one = 0; 
                int zero = 0; 
                if(i-1 >= 0 and j-1>=0) {
                    if(board[i-1][j-1]) one++;
                    else zero++;
                }
                if(i-1 >= 0) {
                    if(board[i-1][j]) one++;
                    else zero++;
                }
                if(i-1 >= 0 and j+1<=n-1) {
                    if(board[i-1][j+1]) one++;
                    else zero++;
                }
                if(j+1<=n-1) {
                    if(board[i][j+1]) one++;
                    else zero++;
                }
                if (j-1>=0){
                    if(board[i][j-1]) one++;
                    else zero++;
                }
                if(i+1<=m-1 and j-1>=0) {
                    if(board[i+1][j-1]) one++;
                    else zero++;
                }
                if(i+1<=m-1) {
                    if(board[i+1][j]) one++;
                    else zero++;
                }
                if(i+1<=m-1 and j+1<=n-1) {
                    if(board[i+1][j+1]) one++;
                    else zero++;
                }
                // cout<<i<<j<<" "<<one<<" "<<zero<<endl;
                
                if(one<2) temp[{i,j}] = 0; 
                else if (one>3) temp[{i,j}] = 0; 
                else if(one==3) temp[{i,j}] = 1; 
                
            }
        }
        
        for(auto it : temp) {
            // cout<<it.first.first<<" "<<it.first.second<<" - "<<it.second<<endl;
            board[it.first.first][it.first.second] = it.second;
        }
    }
};