class Solution {
public:
    static bool compare(vector<int> a, vector<int>b) {
        return (a[1]-a[0])>(b[1]-b[0]);
    }
    
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        
        sort(intervals.begin(), intervals.end(), compare);
        
        // for(auto it : intervals) {
        //     cout<<it[0]<<" "<<it[1]<<endl; 
        // }
        
        int n = intervals.size(); 
        int k = 0; 
        vector<bool>check(n, false);
        
        for(int i = 0; i < n; i++) {
            int start = intervals[i][0]; 
            int end = intervals[i][1]; 
            for(int j = i+1; j < n; j++) {
                if(intervals[j][0]>=start and intervals[j][0]<end and intervals[j][1]>start and intervals[j][1]<=end and !check[j]) {
                    k++; 
                    check[j] = true; 
                }
            }
        }
        
        return n-k; 
    }
};