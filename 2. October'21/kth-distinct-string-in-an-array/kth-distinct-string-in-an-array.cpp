class Solution {
public:
    string kthDistinct(vector<string>& arr, int k) {
        map<string, int> temp; 
        
        for(auto i : arr){
            temp[i] += 1;
        }
        
        for(auto i : arr){
            if(temp[i] == 1){
                --k; 
                if(k==0){
                    return i;
                }
            }
        }
        return "";
    }
};