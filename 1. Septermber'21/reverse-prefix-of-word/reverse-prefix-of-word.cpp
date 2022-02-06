class Solution {
public:
    string reversePrefix(string word, char ch) {
        
        int n = word.size(); 
        int index = -1;
        
        for(int i = 0; i < n; i++) {
            if(word[i] == ch) {
                index = i; 
                break; 
            }
        }
        
        if(index == -1) {
            return word;
        }
        
        
        for(int i = 0 ; i <=index/2; i++) {
            char swap = word[i]; 
            word[i] = word[index-i];
            word[index-i] = swap;
        }
        
        return word;
        
    }
};