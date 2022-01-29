class Solution {
public:
    int largestSubmatrix(vector<vector<int>>& matrix) {
        int m = matrix.size(); 
        int n = matrix[0].size(); 
        int res = 0; 
        vector<int> heights(n,0);
        
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(matrix[i][j]==1) heights[j] += 1;
                else heights[j] = 0;
            }
            
            vector<int> temp = heights;
            sort(temp.begin(), temp.end());
        
            for(int j = 0; j < n; j++) {
                res = max(res, temp[j]*(n-j));
            }
        }
        
        return res;
    }
};