class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        
        string s(n, '.');
        vector<string> board(n, s);
        
        nqueen(0, board, n);
        return ans; 
    }
    
private:
    bool isSafe(int row, int col, vector<string>& board, int n) {
        
        int dupRow = row; 
        int dupCol = col; 
        
        while(row>=0 and col >=0) {
            if(board[row][col]=='Q') return false;
            row--;
            col--;
        }
        
        col = dupCol; 
        row = dupRow;
        while(col>=0) {
            if(board[row][col]=='Q') return false; 
            col--;
        }
        
        row = dupRow; 
        col = dupCol; 
        while(row<n and col>=0) {
            if(board[row][col]=='Q') return false;
            row++;
            col--;
        }
        
        return true; 
    }        
    
    vector<vector<string>> ans; 
    void nqueen(int col, vector<string>& board, int n) {
        if(col==n) {
            ans.push_back(board);
            return;
        }
        
        for(int row = 0; row < n; row++) {
            if(isSafe(row, col, board, n)) {
                board[row][col]='Q';
                nqueen(col+1, board, n);
                board[row][col]='.';
            }
        }
        
        return;
    }

};