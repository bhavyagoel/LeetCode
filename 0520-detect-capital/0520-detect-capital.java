class Solution {
    public boolean detectCapitalUse(String word) {
        int caps = 0; 
        int lastInd = 0;
        for(int i = 0; i < word.length(); i++){
            if(Character.isUpperCase(word.charAt(i))){
                caps++;
                lastInd = i;
            }
        }
        
        if(caps == word.length() || (caps == 1 && lastInd == 0) || caps == 0)
            return true;
        
        return false;
    }
}