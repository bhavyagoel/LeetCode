class Solution {
    public int minimumRounds(int[] tasks) {
        HashMap<Integer, Integer> map = new HashMap<>();
        
        for(int task : tasks)
            map.merge(task, 1, Integer::sum);
        
        int res = 0;
        for(Integer val : map.values()){
            if(val == 1)
                return -1;
            int rem = val % 3;
            if(rem == 0)
                res += val/3;
            else if(rem == 1){
                res += (val-1)/3 + 1;
            }else{
                res += val/3 + 1;
            }
        }
        
        return res;
    }
}