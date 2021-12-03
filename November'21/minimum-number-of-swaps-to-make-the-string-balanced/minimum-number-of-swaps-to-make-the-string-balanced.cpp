// Hints needed

class Solution {
public:
    int minSwaps(string s) {
        int open = 0;
        int close = 0; 
        int n = s.length(); 
        vector<int> opened;
        for(int i = n-1; i > -1; i--) {
            if(s[i] == '[') {
                opened.push_back(i);
            }
        }
        int start = 0;
        int res = 0;
        for(int i =0; i < n; i++) {
            if(s[i]==']') {
                close++;
                if(close > open) {
                    swap(s[i], s[opened[start]]);
                    close--;
                    open++;
                    res++;
                    start++;
                    // cout<<s<<endl;
                }
            }else{
                open++;
            }
        }
        
        return res;
    }
};