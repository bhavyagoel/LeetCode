class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        
        int r = matrix.size(); 
        int c = matrix[0].size(); 
        bool isCol = false; 
        bool isRow = false; 
        
        for(int i = 0 ; i < r; i++) {
            for(int j = 0; j < c; j++) {
                if(matrix[i][j] == 0) {
                    matrix[i][0] = 0; 
                    matrix[0][j] = 0; 
                    
                    if(i == 0) isRow = true; 
                    if(j == 0) isCol = true;
                }
                
                
            }
        }
        
        for(int i = 1 ; i < r; i++) {
            if(matrix[i][0] == 0) {
                for(int j = 0 ; j < c; j++) matrix[i][j] = 0;
            }
        }
        
        for(int i = 1 ; i < c; i++) {
            if(matrix[0][i] == 0) {
                for(int j = 0 ; j < r; j++) matrix[j][i] = 0;
            }
        }
        
        if(isRow) {
            for(int i = 0 ; i < c; i++) matrix[0][i] = 0;
        }
        
        if(isCol) {
            for(int i = 0 ; i < r; i++) matrix[i][0] = 0;
        }

    }
};