struct Local{
    Local(int median) { this->median = median; }
    bool operator () (int a, int b) { 
        int alpha = (a-median)>0?(a-median):(median-a); 
        int beta = (b-median)>0?(b-median):(median-b); 
        
        if(alpha==beta) return a>b; 
        else if(alpha > beta) return true; 
        else return false; 
    }

    int median;
};


class Solution {
public:
    vector<int> getStrongest(vector<int>& arr, int k) {
        sort(arr.begin(), arr.end()); 
        int n = arr.size(); 
        vector<int> res(k, 0); 
        
        int median = arr[(n-1)/2];
        sort(arr.begin(), arr.end(), Local(median));
        for(int i = 0; i < k; i++) res[i] = arr[i];
        return res;
    }
};