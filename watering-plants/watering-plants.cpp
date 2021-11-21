class Solution {
public:
    int wateringPlants(vector<int>& plants, int capacity) {
        int orig = capacity; 
        int res = 0; 
        for(int i = 0 ; i < plants.size(); i++) {
            if(capacity>=plants[i]) {
                res+=1;
                capacity -= plants[i];
            }else {
                capacity=orig; 
                capacity -= plants[i];
                res += 2*i+1; 
            }
        }
        
        return res;
    }
};