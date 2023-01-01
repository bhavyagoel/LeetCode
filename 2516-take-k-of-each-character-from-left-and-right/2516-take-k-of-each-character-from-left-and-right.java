class Solution {
    public int takeCharacters(String s, int k) {
        HashMap<Character, Integer> map = new HashMap<>(); 
        
        for(int i = 0; i < s.length(); i++)
            map.merge(s.charAt(i), 1, Integer::sum);
        
        if(map.getOrDefault('a', 0)<k || map.getOrDefault('b', 0)<k || map.getOrDefault('c', 0)<k)
            return -1;
        
        int j = 0, i = 0;
        int ans = s.length();
        for(i = 0; i < s.length(); i++){
            
            map.merge(s.charAt(i), -1, Integer::sum);
            
            while(map.get(s.charAt(i)) < k)
                map.merge(s.charAt(j++), 1, Integer::sum);
            
            ans = Math.min(ans, s.length()-(i-j+1));
        }
                
        return ans;
    }
}