class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        int n = candidates.size();
        vector<int> ds; 
        RecursiveComb(ds, 0, 0, target, candidates, n);
        return res;
    }
    
private:
    
    vector<vector<int>> res;
    void RecursiveComb(vector<int>&ds, int idx, int s, int target, vector<int>& cd, int n) {
        
        if(idx==n or s>target) return;
        if(s==target) {
            res.push_back(ds);
            return;
        }
        
        ds.push_back(cd[idx]);
        s += cd[idx]; 
        
        RecursiveComb(ds, idx, s, target, cd, n);
        ds.pop_back(); 
        s -= cd[idx]; 
        RecursiveComb(ds, idx+1, s, target, cd, n);
        return;
    }
};