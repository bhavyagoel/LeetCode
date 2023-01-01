class Solution {
public:
    vector<vector<int>> transpose(vector<vector<int>>& arr) {
        int m = arr.size(); 
        int n = arr[0].size();
        
        vector<vector<int>>res(n, vector<int>(m,0));
        
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                res[j][i] = arr[i][j];
            }
        }
        
        return res;
    }
};