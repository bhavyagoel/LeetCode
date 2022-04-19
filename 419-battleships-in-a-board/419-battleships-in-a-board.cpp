class Solution {
public:
    void helper(vector<vector<char>>& board, int i, int j) {
        
        if(i >= board.size()) return; 
        if(j >= board[0].size()) return; 
        
        if(board[i][j] == '.') return;
        
        board[i][j] = '.';
        helper(board, i+1, j);
        helper(board, i, j+1);
        
    }
    
    
    int countBattleships(vector<vector<char>>& board) {
        
        int m = board.size(); 
        int n = board[0].size(); 
        
        int res = 0; 
        
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(board[i][j] == 'X') {
                    res += 1; 
                    helper(board, i, j); 
                }
            }
        }
        
        return res; 
    }
};