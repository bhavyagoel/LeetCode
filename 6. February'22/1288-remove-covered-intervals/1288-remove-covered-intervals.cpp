class Solution {
public:
/*
    static bool compare(vector<int> a, vector<int>b) {
        return (a[1]-a[0])>(b[1]-b[0]);
    }
    
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        
        sort(intervals.begin(), intervals.end(), compare);        
        int n = intervals.size(); 
        int k = 0; 
        vector<bool>check(n, false);
        
        for(int i = 0; i < n; i++) {
            int start = intervals[i][0]; 
            int end = intervals[i][1]; 
            for(int j = i+1; j < n; j++) {
                if(intervals[j][0]>=start and intervals[j][1]<=end and !check[j]) {
                    k++; 
                    check[j] = true; 
                }
            }
        }
        
        return n-k; 
    }
*/
    
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        
        sort(intervals.begin(), intervals.end(), [](vector<int>& a, vector<int>& b) {
            return a[0]==b[0] ? a[1]>b[1] : a[0]<b[0];
        });
        
        int n = intervals.size(); 
        
        int curr = 0; 
        int nxt = 1; 
        
        int k = 0; 
        while(curr<n and nxt<n) {
            if(intervals[curr][0]<=intervals[nxt][0] and intervals[curr][1]>=intervals[nxt][1]) {
                k++;
                nxt++;
            }
            else if(nxt==++curr) nxt++;
        }
        
        return n-k;
    }
};