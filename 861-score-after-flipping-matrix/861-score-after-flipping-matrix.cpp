class Solution {
public:
    int matrixScore(vector<vector<int>>& g) {
        
        int m = g.size(); 
        int n = g[0].size(); 
        for(int i = 0; i < m; i++) {
            int orig = 0; 
            int rev = 0; 
            for(int j = 0; j < n; j++) {
                orig |= g[i][j];
                orig = orig<<1;
                
                rev = rev | (g[i][j]==0?1:0);
                rev = rev<<1;
            }
            orig = orig>>1;
            rev = rev>>1;
            if (orig < rev) {
                for(int j = 0; j < n; j++) {
                    g[i][j] = g[i][j]==0?1:0;
                }
            }
        }        
        
        for(int i = 0; i < n; i++) {
            
            if (checkScore(g, i)) {
                for(int j = 0; j < m; j++) {
                    g[j][i] = g[j][i]==0?1:0;
                }
            }
        }
        
        int res = 0; 
        for(int i = 0; i < m; i++) {
            int orig = 0; 
            for(int j = 0; j < n; j++) {
                orig |= g[i][j];
                orig = orig<<1;
            }
            orig = orig>>1;
            res += orig;
        }
        
        return res;
        
    }
private:
    bool checkScore(vector<vector<int>>& g, int colChg) {
        int res = 0; 
        int other = 0; 
        int m = g.size(); 
        int n = g[0].size(); 
        for(int i = 0; i < m; i++) {
            int orig = 0; 
            int tmp = 0;
            for(int j = 0; j < n; j++) {
                orig |= g[i][j];
                orig = orig<<1;
                
                if(j==colChg){
                    tmp |=  g[i][j]==0?1:0;
                    tmp = tmp<<1;
                }else{
                    tmp |= g[i][j];
                    tmp = tmp<<1;
                }
            }
            orig = orig>>1;
            res += orig;
            
            tmp = tmp>>1;
            other += tmp;
        }
        return other>res;
       
    }
};