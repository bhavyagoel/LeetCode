class Solution {
public:
    int maxRepOpt1(string text) {
        
        vector<vector<int>> count(26);
        int n = text.length();
        for(int i = 0; i < n; i++) {
            count[text[i]-'a'].push_back(i);
        }
        int res = 0;
        for(int i = 0; i < 26; i++) {
            if(count[i].size()>0) {
                int len = count[i].size(); 
                int cnt = 1;
                int cnt1 = 0;
                int mx = 0;
                for(int j = 1; j < len; j++) {
                    
                    if((count[i][j-1]+1)==count[i][j]) ++cnt;
                    else {
                        cnt1 = (count[i][j-1]+2)==count[i][j]?cnt:0;
                        cnt = 1;
                    }
                    
                    mx = max(mx, cnt+cnt1);
    
                }
                res = max(res, mx+(count[i].size()>mx?1:0));
            }
        }
        
        return res;
    }
};