class Solution {
    public boolean wordPattern(String pattern, String s) {
        HashMap<Character, String> map = new HashMap<>();
        int j = 0;
        for(int i = 0; i < pattern.length(); i++){
            String temp = ""; 
            while(j < s.length() && s.charAt(j) != ' '){
                temp += s.charAt(j);
                j++;
            }
            
            if(temp == "")
                return false;
            j++;
            if (map.containsKey(pattern.charAt(i))){
                if(!map.get(pattern.charAt(i)).equals(temp))
                    return false;
            }else{
                if(map.containsValue(temp))
                    return false;
                map.put(pattern.charAt(i), temp);
            }
        }
        if(j < s.length())
            return false;
        return true;
    }
}