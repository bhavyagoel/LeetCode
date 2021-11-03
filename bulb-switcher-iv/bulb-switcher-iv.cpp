class Solution {
public:
    int minFlips(string s) {
        bool flag = false; 
        int count = 0;
        int start = 0; 
        while(s[start]=='0' && start < s.length()) start++;
        for(int i = start ; i < s.length(); i++){
            if(s[i] == '1' && flag==false){
                count++; 
                flag = true; 
                while(s[i] == '1') i++; 
                i--;
            }
            if(s[i] == '0' && flag==true){
                count++;
                flag = false; 
                while(s[i] == '0') i++;
                i--;
            }
        }
        
        return count; 
    }
};