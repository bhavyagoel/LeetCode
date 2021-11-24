class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& A, vector<vector<int>>& B) {
        vector<vector<int>> res;
        
        int m = A.size(), n = B.size(); 
        for(int i = 0, j = 0; i<m && j<n; A[i][1]<B[j][1]?i++:j++) {
            int start = max(A[i][0], B[j][0]);
            int end = min(A[i][1], B[j][1]);
            
            if(start<=end) res.push_back({start, end});
        }
        
        return res;
        
    }
};