class Solution {
public:
    int maximumWealth(vector<vector<int>>& acc) {
     int maxm =0;
        for(auto &it : acc){
            int can =0;
            for(auto &c: it){
                can+=c;
            }
            maxm=max(maxm, can);
        }
        return maxm;
    }
};