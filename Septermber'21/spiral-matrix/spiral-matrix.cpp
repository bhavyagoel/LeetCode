class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& arr) {
        vector<int> res;
        
        int nr = arr.size(); 
        int nc = arr[0].size(); 
        
        
        int rowBeg = 0; 
        int colBeg = 0;
        int rowEnd = nr-1;
        int colEnd = nc-1; 
        
        
        while(rowBeg <= rowEnd && colBeg<= colEnd) {
            
            for(int i = colBeg; i<= colEnd; i++) {
                res.push_back(arr[rowBeg][i]);
            }
            
            // colEnd--;
            rowBeg++;
            
            for(int i = rowBeg; i <= rowEnd; i++) {
                res.push_back(arr[i][colEnd]);
            }
            
            colEnd--; 
            
            
            if(rowBeg <= rowEnd){
                for(int i = colEnd; i >= colBeg; i--) {
                    res.push_back(arr[rowEnd][i]);
                }
            }
            
            
            rowEnd--;
            
            if(colBeg<= colEnd) {
                for(int i = rowEnd; i >= rowBeg; i-- ) {
                    res.push_back(arr[i][colBeg]);
                }
            }
            
            
            colBeg++;
            
        }
        
        return res;
    }
    
};