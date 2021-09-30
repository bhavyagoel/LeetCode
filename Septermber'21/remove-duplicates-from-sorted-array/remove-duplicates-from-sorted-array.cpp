class Solution {
public:
    int removeDuplicates(vector<int>& arr) {
        int n = arr.size();
        int k = 1;
        if (n!=0) {
            for(int i = 0 ; i < n-1; i++) {
                if (arr[i] != arr[i+1]) {
                    arr[k] = arr[i+1];
                    k+=1;
                }
                else {
                    continue;
                }
            }
            return k;
        }
        
        return 0;
    }
};