class Solution {
public:
    string largestTimeFromDigits(vector<int>& arr) {
        permutate(arr, 0);
        int hourMax = -1;
        int minMax = -1; 
        
        for(auto time : allPerm) {
            int hr = time[0]*10 + time[1];
            int min = time[2]*10 + time[3];
            
            if(hourMax < hr) {
                hourMax = hr;
                minMax = min;
            }
            if (hourMax == hr and minMax<min) {
                minMax = min;
            }
            
        }
        if(hourMax==-1 or minMax==-1) return "";
        
        
        string min = to_string(minMax);
        min = min.length()==2?min:"0"+min;
        
        string hr = to_string(hourMax);
        
        hr = hr.length()==2?hr:"0"+hr;
        string res = hr +":" + min;
        return res;
    }
    
    
private:
    vector<vector<int>> allPerm; 
    void permutate(vector<int>&arr, int idx){
        if(idx == 4){
            int hr = arr[0]*10 + arr[1];
            int min = arr[2]*10 + arr[3];
            
            if(hr<24 and min<60) {
                allPerm.push_back(arr);
            }
            return;
        }
        
        for(int i = idx; i < 4; i++) {
            swap(arr[idx], arr[i]);
            permutate(arr, idx+1);
            swap(arr[idx], arr[i]);
        }
    }
};