class Solution {
public:
    bool hasAllCodes(string s, int k) {
        int size = pow(2, k);
        vector<int>arr(size, 0);
        // int arr[size] = {0};
        
        int curr = 0; 
        int tmp = 0; 
        for(int i = s.size()-1; i > -1 and i > s.size()-1-k; i--) {
            
            if(s[i] != '0') curr |= (1<<(tmp));
            tmp++;
        }
        // cout<<curr<<endl;
        arr[curr] = 1;
        for(int i = s.size()-1-k; i > -1; i--) {
            curr = curr >> 1;
            if(s[i] != '0') curr |= (1 << (k-1));
            // cout<<curr<<endl;
            arr[curr] = 1;
        }
        
        for(int i = 0; i < arr.size(); i++) {
            if(arr[i]==0) return false; 
        }
        
        return true;
    }
};