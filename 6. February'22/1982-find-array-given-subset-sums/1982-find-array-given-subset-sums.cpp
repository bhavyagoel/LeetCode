// https://leetcode.com/problems/find-array-given-subset-sums/discuss/1437739/Recursive-Disambiguation
// Important Mathematical Intuitution

class Solution {
public:
    vector<int> recoverArray(int n, vector<int>& sums) {
            
        sort(sums.begin(), sums.end());
        vector<int> res; 
        
        while(sums.size()>1) {
            vector<int> l, r; 
            int num = sums[1]-sums[0], l_zero = false;
            
            for(int i = 0, j = 0; i < sums.size(); ++i) {
                if(sums[i]==INT_MIN) continue; 
                
                l_zero |= (sums[i]==0);
                
                l.push_back(sums[i]);
                r.push_back(sums[i]+num);
                
                for (j = max(j + 1, i + 1); sums[j] != (sums[i] + num); ++j); 
                sums[j] = INT_MIN;
            }            
            
            res.push_back(num*(l_zero?1:-1));
            swap(sums, l_zero?l:r);
            
        }
        
        return res; 
        
    }
    
};