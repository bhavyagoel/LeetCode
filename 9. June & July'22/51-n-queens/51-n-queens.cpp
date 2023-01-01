class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        
        string s(n, '.');
        vector<bool> sameRow(n, false);
        vector<bool> mainDiag(2*n-1, false);
        vector<bool> crossDiag(2*n-1, false);
        vector<string> board(n, s);
        
        nqueen(0, board, n, sameRow, mainDiag, crossDiag);
        return ans; 
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
    vector<vector<string>> ans;
    
    void nqueen(int col, vector<string>& board, int n, vector<bool> &sameRow, vector<bool>& mainDiag, vector<bool> &crossDiag) {
        if(col==n) {
            ans.push_back(board);
            return;
        }
        
        for(int row = 0; row < n; row++) {
            /**
            if(isSafe(row, col, board, n)) {
                board[row][col]='Q';
                nqueen(col+1, board, n);
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
                nqueen(col+1, board, n, sameRow, mainDiag, crossDiag);
                board[col][row]='.';
                sameRow[row] = false; 
                mainDiag[mainD] = false; 
                crossDiag[crossD] = false; 
            }
        }
        
        return;
    }

};