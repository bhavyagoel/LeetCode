// BRUTE FORCE APPROACH USING NEXT SMALLER ELEMNT AND PREV SMALLER ELEMENT
class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        // We can start by calculating next smaller element and prev smaller element. Make sure to set their indices as the widhth would be the distance between them
        
        stack<int> left;
        stack<int> right; 
        
        int n = heights.size(); 
        vector<int> leftBound(n,0); 
        vector<int> rightBound(n,n-1);
        
        for(int i = 0; i < n; i++) {
            
            while(left.size() and heights[left.top()]>=heights[i]) {
                left.pop();
            }
            
            leftBound[i] = left.size()?left.top()+1:0;
            left.push(i);
            
            while(right.size() and heights[right.top()]>=heights[n-i-1]) {
                right.pop();
            }
            rightBound[n-i-1] = right.size()?right.top()-1:n-1;
            right.push(n-i-1);
        }
        
        int res = 0; 
        for(int i = 0; i < n; i++) {
            int tot = rightBound[i] - leftBound[i] + 1;
            res = max(res, heights[i]*tot);
        }
        
        return res;
    }
};