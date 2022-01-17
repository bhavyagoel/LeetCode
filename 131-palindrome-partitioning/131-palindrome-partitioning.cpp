class Solution {
public:
    vector<vector<string>> partition(string s) {
        vector<string> arr;
        int n = s.length();
        partition(s, arr, 0, n);
        return res; 
    }
    
private:
    vector<vector<string>> res; 
    
    void partition(string& s, vector<string>& arr, int idx, int n) {
        if(idx==n) {
            res.push_back(arr);
            return;
        }
        
        string word = "";
        for(int i = idx; i < n; i++) {
            word.push_back(s[i]);
            if(checkPalind(word)) {
                arr.push_back(word);
                partition(s, arr, i+1, n);
                arr.pop_back();
            }
        }
        return;
    }
    
    
    bool checkPalind(string s) {
        int i = 0; 
        int j = s.length()-1; 
        
        while(j>=i) {
            if(s[i]!=s[j]) return false;
            j--;
            i++;
        }
        
        return true;
    }
};