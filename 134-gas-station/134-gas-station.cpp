class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = gas.size(); 
        int strt = 0;
        int diff = 0; 
        int currDiff = 0; 
        for(int i = 0; i < n; i++) {
            int tmp = gas[i]-cost[i];
            diff += tmp;
            currDiff += tmp; 
            
            // Peeche waalo ka sum negative nhi hona chahiye
            if(currDiff<0) {
                currDiff=0;
                strt = i+1;
            }
        }
        
        if(diff<0) return -1;
        return strt;
    }
};