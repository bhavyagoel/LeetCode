class Solution {
public:
    vector<int> replaceElements(vector<int>& arr) {
        int n = arr.size();
        int large = -1;
        
        for(int i = n-1; i > -1; i--) {
            int temp = arr[i]; 
            arr[i] = large; 
            if(large<temp) {
                large = temp;
            }
        }
        
        return arr;
    }
};