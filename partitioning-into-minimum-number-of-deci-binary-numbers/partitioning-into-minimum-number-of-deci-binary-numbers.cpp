class Solution {
public:
    int minPartitions(string n) {
        
        int res = INT_MIN;        
        for(int i = 0 ; i < n.length(); i++){
            res = max(res, n[i]-'0');
        }
        return res; 
    }
};