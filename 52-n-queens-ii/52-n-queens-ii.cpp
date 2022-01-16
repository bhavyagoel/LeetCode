class Solution {
public:
    int totalNQueens(int n) {
        string s(n, '.');
        vector<string> board(n, s);
        return nqueen(0, board, n);
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
    
    int nqueen(int col, vector<string>& board, int n) {
        if(col==n) {
            return 1;
        }
        int count = 0; 
        for(int row = 0; row < n; row++) {
            if(isSafe(row, col, board, n)) {
                board[row][col]='Q';
                count += nqueen(col+1, board, n);
                board[row][col]='.';
            }
        }
        
        return count;
    }
};