class Solution {
public:
    int majorityElement(vector<int>& arr) {
        
        int major;
        int n = arr.size();
        int count = 0;
        for (int i = 0 ; i < n; i++) {
            if (count == 0) {
                count++;
                major = arr[i];
            }
            else if(major == arr[i]){
                count++;
            }
            else {
                count --;
            }
        }
        return major;
    }
};