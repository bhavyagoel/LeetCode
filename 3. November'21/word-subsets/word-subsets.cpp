class Solution {
public:
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
        
        vector<int> all(26,0);
        
        for(int i = 0 ; i < words2.size(); i++) {
            vector<int> temp(26,0);
            for(auto alpha : words2[i]) {
                temp[alpha-'a']++;
            }
            
            for(int j = 0 ; j < 26; j++) {
                if(all[j] < temp[j]) all[j] = temp[j];
            }
        }
        
        vector<string> res; 
        
        for(int i = 0 ; i < words1.size(); i++) {
            vector<int> temp = all; 
            for(auto alpha : words1[i]) {
                temp[alpha-'a']--;
            }
            
            bool check = true; 
            for(int j = 0 ; j < 26; j++) {
                if(temp[j] > 0) {
                    check = false; 
                    break;
                }
            }
            
            if (check) res.push_back(words1[i]);
        }
        
        return res; 
    }
};