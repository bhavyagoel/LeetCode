class Solution {
    public int minDeletionSize(String[] strs) {
        
        int m = strs.length; 
        int n = strs[0].length(); 
        int res = 0;
        for(int i = 0; i < n; i++){
            int j = 0; 
            char prev = strs[j].charAt(i);
            while(j < m){
                if(prev > strs[j].charAt(i)){
                    res++;
                    break;
                }
                prev = strs[j].charAt(i);
                j++;
            }
        }
        
        return res; 
    }
}