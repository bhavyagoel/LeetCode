class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        
        vector<vector<int>>res(n , vector<int> (n, 0)); 
                
        int num = 1; 
        
        int rowBeg = 0; 
        int colBeg = 0; 
        int rowEnd = n-1; 
        int colEnd = n-1; 
        
        while(rowBeg <= rowEnd && colBeg <= colEnd) {
            
            for(int i = colBeg; i <= colEnd; i++) {
                res[rowBeg][i] = num;
                num++;
            }
            
            rowBeg++;
            
            for(int i = rowBeg; i <= rowEnd; i++) {
                res[i][colEnd] = num;
                num++; 
            }
            
            colEnd--;
            
            if(rowBeg <= rowEnd){
                for(int i = colEnd; i>= colBeg; i--) {
                    res[rowEnd][i] = num;
                    num++;
                }
            }
            
            rowEnd--;
            
            if(colBeg <= colEnd) {
                for(int i = rowEnd; i>=rowBeg; i--) {
                    res[i][colBeg] = num;
                    num++;
                }
            }
            colBeg++;
            
        }
        
        return res;
    }
};



