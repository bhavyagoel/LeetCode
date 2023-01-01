class Solution {
    public int minimumPartition(String s, int k) {
        
        int ans = 0; 
        int i = 0;
        while(i < s.length()){
            String temp = "" + s.charAt(i);
            int j = i+1;
            if(Integer.parseInt(temp) > k)
                return -1; 
            
            while(j < s.length()){
                if(Long.parseLong(temp + s.charAt(j)) >= (long)k)
                    break;
                temp += s.charAt(j++);
            }
            
            ans++;
            i = j;
        }
        return ans; 
    }
}