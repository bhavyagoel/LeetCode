class Solution {
public:
    int totalNQueens(int n) {
        string s(n, '.');
        vector<string> board(n, s);
        
        vector<bool> sameRow(n, false);
        vector<bool> mainDiag(2*n-1, false);
        vector<bool> crossDiag(2*n-1, false);
        
        return nqueen(0, board, n, sameRow, mainDiag, crossDiag);
        
    }
    
private:
    /**
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
    **/
    
     int nqueen(int col, vector<string>& board, int n, vector<bool> &sameRow, vector<bool>& mainDiag, vector<bool> &crossDiag) {
        if(col==n) {
            return 1;
        }
        int count = 0; 
        for(int row = 0; row < n; row++) {
            /**
            if(isSafe(row, col, board, n)) {
                board[row][col]='Q';
                count += nqueen(col+1, board, n);
                board[row][col]='.';
            }
            **/
            int mainD = row+col; 
            int crossD = (n-1)+ (col-row);
            
            if(!sameRow[row] and !mainDiag[mainD] and !crossDiag[crossD]) {
                board[col][row]='Q';
                sameRow[row] = true; 
                mainDiag[mainD] = true; 
                crossDiag[crossD] = true; 
                count += nqueen(col+1, board, n, sameRow, mainDiag, crossDiag);
                board[col][row]='.';
                sameRow[row] = false; 
                mainDiag[mainD] = false; 
                crossDiag[crossD] = false; 
            }
        }
        
        return count;
    }
};