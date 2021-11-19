class Solution {
public:
    int minimumLength(string s) {
        
        int n = s.length();
        if(n==1) return 1;
        int cnt = 0;
        for(int i = 0, j = n-1 ; j>=i; i++,j--) {
            if(j==i) return 1;
            if(s[i] == s[j]) {
                char temp = s[i]; 
                while(s[i] == temp && i<j) {
                    i++; 
                    cnt++;
                }
                i--; 
                while(s[j] == temp && j>i){
                    j--; 
                    cnt++;
                }
                j++;
                
            }else{
                break;
            }
            
        }
        return (n-cnt)>=0?(n-cnt):0; 
    }
};