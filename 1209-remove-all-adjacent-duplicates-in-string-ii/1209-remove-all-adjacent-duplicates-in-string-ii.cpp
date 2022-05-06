class Solution {
public:
    string removeDuplicates(string s, int k) {
        
        stack<pair<char, int>> temp; 
        int n = s.size(); 
        
        for(int i = 0; i < n; i++) {
            
            if(temp.empty()) temp.push({s[i], 1});
            else {
            
                pair<char, int> prev = temp.top(); 
                
                if(prev.first == s[i]) temp.push({s[i], prev.second+1});
                else temp.push({s[i], 1});
            }
            
            
            pair<char, int> prev = temp.top(); 
            if(prev.second == k) {
                int tmp = k;
                while(tmp--) temp.pop(); 
            }
        }
        
        string res = ""; 
        while(!temp.empty()){
            pair<char, int> prev = temp.top(); 
            res += prev.first; 
            temp.pop(); 
        }
        
        reverse(res.begin(), res.end()); 
        return res; 
    }
};