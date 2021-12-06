class Solution {
public:
    int minCostToMoveChips(vector<int>& position) {
        
        int evenCost = 0; 
        int oddCost = 0; 
        int n = position.size();
        for(int i = 0 ; i < n; i++) {
            if (position[i]%2) oddCost += 1;
            else evenCost += 1;
        }
        
        return min(oddCost, evenCost);
    }
};