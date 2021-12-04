/*
class Solution {
public:
    int countVowelStrings(int n) {
        int a=1,e=1,i=1,o=1,u=1;
        
        while(n>1) {
            a = a+e+i+o+u;
            e = e+i+o+u;
            i = i+o+u;
            o = o+u;
            u = u;
            n--;
        }
        return a+e+i+o+u;
    }
};

*/

class Solution {
public:
    int countVowelStrings(int n) {
        return (n+1)*(n+2)*(n+3)*(n+4)/24;
    }
};


/*
class Solution {
public:
    int countVowelStrings(int n) {
        return dynamic(n,0);
        
    }
        
    int dp[35][6];
    int dynamic(int n,int i) {
        if (dp[n][i]) return dp[n][i];
        
        if(n==0) return 1; 
        if(i==5) return 0; 

        int ans = dynamic(n,i+1);
        ans += dynamic(n-1,i);
        return dp[n][i] = ans;
    }
};
*/