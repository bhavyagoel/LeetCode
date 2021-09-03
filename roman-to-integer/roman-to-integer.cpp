class Solution {
public:
    int romanToInt(string s) {
        int n = s.size(); 
        
        map <char, int> umap;
        umap['I'] = 1;
        umap['V'] = 5;
        umap['X'] = 10;
        umap['L'] = 50;
        umap['C'] = 100;
        umap['D'] = 500;
        umap['M'] = 1000;
        int count = 0;
        // int flag = 0;
        for(int i = 0 ; i < n-1; i++) {
            if (umap[s[i]] < umap[s[i+1]]) {
                count += (umap[s[i+1]] - umap[s[i]]);
                i++;
                // flag = 0;
            }
            
            else {
                count += umap[s[i]];
                // flag = 1;
            }
        }
        
        if (n>2) {
        
            if (umap[s[n-2]] >= umap[s[n-1]]) {
                count += umap[s[n-1]];
            }
        }
        
        else if (n==2) {
            if (umap[s[0]] >= umap[s[1]]) {
                count += umap[s[n-1]];
            }
        }
        else if (n==1) {
            return umap[s[0]];
        }
        
        return count;
        
    }
};