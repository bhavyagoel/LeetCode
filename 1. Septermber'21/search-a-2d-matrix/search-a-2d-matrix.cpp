class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        return helper(matrix, target);
    }
    
private:
    bool helper(vector<vector<int>> &matrix, int target) {
        int m = matrix.size(); 
        int n = matrix[0].size(); 
        
        // Finding the minumum possible positive difference between arr[i][n-1] & target
        int min_diff = INT_MAX; 
        int i = 0; 
        int j = m-1;
        int rowNum = 0;
        while(i<=j) {
            int mid = i + (j-i)/2;
            int diff = matrix[mid][n-1] - target;
            if(diff == 0) {
                return true;
            }
            else if(diff < 0) {
                i = mid+1;
            }
            else {
                if(min_diff > diff) {
                    rowNum = mid;
                    min_diff = diff; 
                }
                j = mid-1; 
            }
        }
        
        // Checking in the particular row
        i = 0; 
        j = n-1; 
        while(i<=j) {
            int mid = i + (j-i)/2;
            
            if(matrix[rowNum][mid] == target) {
                return true;
            }
            else if (matrix[rowNum][mid] > target) {
                j = mid-1; 
            }
            else {
                i = mid+1; 
            }
        }
        return false; 
    }
};