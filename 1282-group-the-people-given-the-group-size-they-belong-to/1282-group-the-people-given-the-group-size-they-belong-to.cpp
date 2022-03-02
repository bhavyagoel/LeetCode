class Solution {
public:
    vector<vector<int>> groupThePeople(vector<int>& gS) {
        vector<vector<int>> res; 
        
        map<int, vector<int>> freq; 
        int n = gS.size(); 
        for(int i = 0; i < n; i++) {
            freq[gS[i]].push_back(i); 
        }
        
        for(auto it : freq) {
            int size = it.first; 
            int i = 0; 
            while(i<it.second.size()) {
                vector<int> temp; 
                for(int j = 0; j < size; j++) {
                    temp.push_back(it.second[i]);
                    i++;
                }
                res.push_back(temp); 
            }
            
        }
        return res; 
    }
};