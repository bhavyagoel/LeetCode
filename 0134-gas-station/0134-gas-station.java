class Solution {
    public int canCompleteCircuit(int[] gas, int[] cost) {
        
        int currRes = 0; 
        int start = 0;
        int totRes = 0;
        for(int i = 0; i < gas.length; i++){
            int tmp = gas[i] - cost[i];
            currRes += tmp;
            totRes += tmp;
            
            if(totRes < 0) {
                start = i + 1;
                totRes = 0;
            }
        }
        
        if(currRes<0)
            return -1;
        
        return start;
    }
}