class NumMatrix {
public:
    
    int dp[201][201]; 
    NumMatrix(vector<vector<int>>& matrix) {
        if (matrix.size() == 0 || matrix[0].size() == 0) return;

        int m = matrix.size(); 
        int n = matrix[0].size(); 
        
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                dp[i][j+1] = dp[i][j] + matrix[i][j];
            }
            
        }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        int sum = 0;
        for (int row = row1; row <= row2; row++) {
            sum += dp[row][col2 + 1] - dp[row][col1];
        }
        return sum;
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */