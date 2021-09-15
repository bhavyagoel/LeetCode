class Solution {
public:
    int maxTurbulenceSize(vector<int>& arr) {
        
        int n = arr.size(); 
        
        // x+y > z
        vector<int> alpha;
        int count = 1;
        int i = 0; 
        int j = 1; 
        
        while(j<n){
            if(arr[i]>arr[j] && i%2!=0) {
                count++;
                alpha.push_back(count);
            }
            else if(arr[i] < arr[j] && i%2==0) {
                count++; 
                alpha.push_back(count);
            }
            else {
                count = 1; 
            }
            i++;
            j++;
            
        }
        
        count = 1;
        i = 0; 
        j = 1; 
        
        while(j<n){
            if(arr[i]>arr[j] && i%2==0) {
                count++;
                alpha.push_back(count);
            }
            else if(arr[i] < arr[j] && i%2!=0) {
                count++; 
                alpha.push_back(count);
            }
            else {
                count = 1; 
            }
            i++;
            j++;
            
        }
        
//         for(auto i : alpha) {
//             cout<<i<<" ";
//         }
//         cout<<endl;
        
        int max = 1; 
        for(auto i : alpha) {
            if (max < i) {
                max = i;
            }
        }
        return max;
        
    }
};