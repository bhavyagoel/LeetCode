class Solution {
public:
    vector<int> luckyNumbers (vector<vector<int>>& matrix) {
        
        vector<int> ans; 
        int m = matrix.size(); 
        int n = matrix[0].size(); 
        
        int min_row[m][n];
        int max_col[m][n];
        
        memset(&min_row, 0, sizeof(min_row));
        memset(&max_col, 0, sizeof(max_col));
        
        // Finding min row
        for(int i = 0 ; i < m ; i++) {
            int min = INT_MAX; 
            int index = -1; 
            for(int j = 0 ; j < n ; j++) {
                if(min > matrix[i][j]) {
                    min = matrix[i][j];
                    index = j;
                }
            }
            min_row[i][index] = 1;
        }
        
        // Finding max col
        for(int i = 0 ; i < n ; i++) {
            int max = INT_MIN; 
            int index = -1; 
            for(int j = 0 ; j < m ; j++) {
                if(max < matrix[j][i]) {
                    max = matrix[j][i];
                    index = j;
                }
            }
            max_col[index][i] = 1;
        }
        
        for(int i = 0 ; i < m ; i++) {
            for (int j = 0 ; j < n ; j++) {
                cout<<matrix[i][j]<<" ";
            }
            cout<<endl;
        }
        
        cout<<endl;
        
        for(int i = 0 ; i < m ; i++) {
            for (int j = 0 ; j < n ; j++) {
                cout<<min_row[i][j]<<" ";
            }
            cout<<endl;
        }
        
        cout<<endl;
        
        for(int i = 0 ; i < m ; i++) {
            for (int j = 0 ; j < n ; j++) {
                cout<<max_col[i][j]<<" ";
            }
            cout<<endl;
        }
        
        cout<<endl;
        
        
        for(int i = 0 ; i < m ; i++) {
            for(int j = 0 ; j< n; j++) {
                if ((max_col[i][j] == min_row[i][j]) && (min_row[i][j] == 1)) {
                    ans.push_back(matrix[i][j]);
                }
            } 
        }
        
        return ans;
        
        
    }
};