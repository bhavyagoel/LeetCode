class Solution {
public:
    int numSpecialEquivGroups(vector<string>& words) {
        
        unordered_set<string> res; 
        for(int i = 0 ; i < words.size(); i++){
            string even = ""; 
            string odd = ""; 
            for(int j = 0 ; j < words[i].length(); j++){
                if(j%2) even+= words[i][j];
                else odd+=words[i][j];
            }
            sort(even.begin(), even.end()); 
            sort(odd.begin(), odd.end()); 
            
            res.insert(even+odd);
        }
        return res.size();
    }
};