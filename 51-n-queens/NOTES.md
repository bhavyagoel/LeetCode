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
​
};
```
​
​
​
We can further optimise the space by creating lists of size as following:
​
For row - n;
For main diagonal - 2n-1;  (Formula: row+col)
For cross diagonal- 2n-1; (Formula: ((n-1) + (col-row))