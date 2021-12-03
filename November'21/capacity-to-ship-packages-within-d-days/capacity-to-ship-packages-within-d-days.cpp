class Solution {
public:
    
    int check_days(vector<int>& weights, int capacity) {
        
        int res = 0; 
        int sum = 0; 
        for(int i = 0 ; i < weights.size(); i++) {            
            while(sum+weights[i] <= capacity and i < weights.size()) {
                sum += weights[i];
                i++;
                if (i == weights.size()) break;
            }            
            i--;
            sum = 0;
            res++;
        }
        return res;
    }
    
    int shipWithinDays(vector<int>& weights, int days) {
        
        int max_cap = 0; 
        int min_cap = INT_MIN;
        for(int i = 0 ; i < weights.size(); i++) {
            max_cap += weights[i];
            min_cap = max(min_cap, weights[i]);
        }
        
        int lo = min_cap; 
        int hi = max_cap; 
        while(lo<hi) {
            int mid = lo + (hi-lo)/2;
            int prob_days = check_days(weights, mid);
            if (prob_days > days) lo = mid+1; 
            else hi = mid;
            
        }
        return lo;
    }
};