class Solution {
public:
    bool canReach(vector<int>& arr, int start) {
        
        int n = arr.size(); 
        stack<int> currVisit; 
        vector<bool> visitedIndex(n, false);
        
        currVisit.push(start);
        
        while(!currVisit.empty()) {
            
            int idx = currVisit.top();
            int idxVal = arr[idx];
            currVisit.pop(); 
            
            if(!visitedIndex[idx]) {
                
                visitedIndex[idx] = true; 
                int backMove = idx-idxVal;
                int forwMove = idx+idxVal;
                
                if(idxVal==0) return true; 
                
                
                if (backMove >= 0) currVisit.push(backMove);
                if (forwMove < n) currVisit.push(forwMove);
            }            
        }
        return false;
    }
};