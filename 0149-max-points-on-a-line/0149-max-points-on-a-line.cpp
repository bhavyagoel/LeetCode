class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        
        if(points.size()==1)
            return 1; 
        
        int maxCnt = 0; 
        for(int i = 0; i < points.size(); i++){
            map<double, int> slpCnt; 
            for(int j = i+1; j < points.size(); j++){
                double x1 = points[i][0];
                double y1 = points[i][1];
                double x2 = points[j][0];
                double y2 = points[j][1];
                
                double slope = (x2!=x1)?((y2-y1)/(x2-x1)):INT_MAX;
                slpCnt[slope]++;

                maxCnt = max(slpCnt[slope], maxCnt);
            }
        }
        
        return maxCnt+1;
    }
};