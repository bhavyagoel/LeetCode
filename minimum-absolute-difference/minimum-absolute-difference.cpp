class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        sort(arr.begin(), arr.end()); 
        int n = arr.size();
        int minDiff = INT_MAX;
        for(int i = 0 ; i < n-1; i++) {
            minDiff = min(minDiff, arr[i+1]-arr[i]);
        }
        
        vector<vector<int>> res; 
        for(int i = 0; i < n-1; i++) {
            if(minDiff == (arr[i+1]-arr[i])){
                res.push_back({arr[i],arr[i+1]});
            }
        }
        
        return res; 
        
    }
};