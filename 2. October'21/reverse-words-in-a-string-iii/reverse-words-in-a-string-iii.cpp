class Solution {
public:
    string reverseWords(string s) {
        int i = 0; 
        while(i<s.length()) {
            int j = i;
            while(j<s.length() && s[j] != ' ') {
                j++;
            }
            j--;
            int count = 0; 
            for(int k = i; k <= i+(j-i)/2; k++){
                swap(s[k], s[j-count]);
                count++;
            }
            i = j+2;
        }
        return s;
    }
};