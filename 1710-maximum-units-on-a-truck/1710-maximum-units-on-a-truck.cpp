class Solution {
public:
    
    static bool comp(vector<int>a, vector<int> b) {
        return a[1] > b[1];
    }
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        sort(boxTypes.begin(), boxTypes.end(), comp);
        int res = 0; 
        
        for(auto &it : boxTypes) {
            if(truckSize==0) return res; 
            
            if(it[0]<=truckSize) {
                truckSize -= it[0];
                res += it[1]*it[0];
            }else{
                res += it[1]*truckSize;
                truckSize = 0;
            }
        }
        
        return res; 
    }
};