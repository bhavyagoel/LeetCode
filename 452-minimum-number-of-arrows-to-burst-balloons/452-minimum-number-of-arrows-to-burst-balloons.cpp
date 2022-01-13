class Solution {
public:
    static bool sortFc(vector<int>& a, vector<int>& b) {
        return a[1]<b[1];
    }
    
    int findMinArrowShots(vector<vector<int>>& points) {
        
        sort(points.begin(), points.end(), sortFc); 
        
        int n = points.size();
        int res = 0; 
        
        int start, end; 
        for(int i = 0; i < n; i++) {
            start = points[i][1];
            while(i<n-1 and start>=points[i+1][0]) i++;
            // i--;
            res++;
        }
        
        return res; 
    }
};