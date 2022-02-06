class Solution {
public:
    int maxArea(vector<int>& height) {
        
        int i = 0; 
        int j = height.size()-1; 
        int res = INT_MIN; 
        while(i!=j) {
            int area;
            if(height[i]<height[j]) {
                area = min(height[i], height[j])*(j-i);
                i+=1; 
            }else{
                area = min(height[i], height[j])*(j-i);
                j-=1; 
            }
            
            res = max(res, area);
        }
        
        return res;
    }
};