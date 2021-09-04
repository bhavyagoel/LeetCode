class Solution {
public:
    int majorityElement(vector<int>& arr) {
        sort(arr.begin(), arr.end());
        
        int n = arr.size();
        int check = ceil(n/2);
        int count = 1;
        
        for(int i = 0 ; i <n-1; i++) {
            if (arr[i] == arr[i+1]) {
                count+=1;
            }
            else {
                count = 1;
            }
            
            if (count > check) {
                return arr[i];
            }
        }
                
        return arr[0];
    }
};