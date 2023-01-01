class Solution {
public:
    vector<int> pathInZigZagTree(int label) {
        
        vector<int> res; 
        int lvl = 0, actual = 1;
        int currLvl = floor(log2(label));
        
        while(label) {
            res.push_back(label); 
            int minCurr = pow(2, currLvl);
            int maxCurr = pow(2, currLvl+1) - 1;
            
            label = ((maxCurr + minCurr) - label)/2;
            currLvl--;
        }
        
        reverse(res.begin(), res.end());
        return res; 
    }
};