class Solution {
public:
    int getXORSum(vector<int>& arr1, vector<int>& arr2) {
        int a1 = 0; 
        int n = arr1.size(); 
        int m = arr2.size(); 
        for(int i = 0 ; i < n; i++) {
            a1 ^= arr1[i];
        }
        
        int b1 = 0; 
        for(int i = 0 ; i < m; i++) {
            b1 ^= arr2[i];
        }
        return a1&b1;
    }
};