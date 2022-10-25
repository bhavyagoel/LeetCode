class Solution {
public:
    bool arrayStringsAreEqual(vector<string>& word1, vector<string>& word2) {
        
        int k = 0, l = 0; 
        int i = 0, j = 0; 
        
        while(k < word1.size() and l < word2.size()){
            while(i<word1[k].size() and j<word2[l].size()){
                if(word1[k][i]==word2[l][j]){
                    i++;
                    j++;
                } 
                else return false;
                
                if(i==word1[k].size()) {
                    i = 0; 
                    k = k + 1;
                }
                
                if(j==word2[l].size()){
                    j = 0; 
                    l = l + 1; 
                }
                
                if(k==word1.size() and l==word2.size()) return true;
                if(k==word1.size() or l==word2.size()) return false;
            }
        }
        return false;
    }
};