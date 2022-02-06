class Solution {
public:
    int numBouquet(vector<int> arr, int day, int k) {
        
        int n = arr.size(); 
        for(int i=0; i < n; i++) {
            arr[i]-=day;
        }
        
        int res = 0;
        int tmp = 0;
        for(int i = 0; i < n; i++) {
            if(arr[i]<=0){
                tmp++;
            }else{
                tmp=0;
            }
            if(tmp==k) {
                tmp=0;
                res++;
            }
        }
        return res;
    }
    
    int minDays(vector<int>& arr, int m, int k) {
        
        int lo = INT_MAX; 
        int hi = INT_MIN;
        
        int n = arr.size(); 
        for(int i = 0; i < n; i++) {
            lo = min(lo, arr[i]);
            hi = max(hi, arr[i]);
        }
        bool check = false; 
        hi+=1;
        lo-=1;
        
        while(lo<hi) {
            
            int mid = lo + (hi-lo)/2;
            int count = numBouquet(arr, mid, k);

            if(count<m) lo=mid+1; 
            else {
                hi = mid;
                check=true;
            }
        }
        
        return check?lo:-1; 
    }
};