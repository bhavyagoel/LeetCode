class Solution {
public:
    int majorityElement(vector<int>& arr) {
        sort(arr.begin(), arr.end());
        
        int n = arr.size();
        int check = ceil(n/2);        
        return arr[check];
    }
};