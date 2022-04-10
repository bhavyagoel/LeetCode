class Solution {
public:
    int maxArea(vector<int>& height) {
        
        int i = 0; 
        int j = height.size()-1; 
        int res = INT_MIN; 
        while(i<j) {
            res = max(res, min(height[i], height[j])*(j-i));
            if(height[i]<height[j]) {
                i+=1; 
            }else{
                j-=1; 
            }
        }
        
        return res;
    }
};