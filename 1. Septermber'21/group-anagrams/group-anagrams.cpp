class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {

        return helper(strs);
    }
    
private:
    vector<int> prims = {2, 3, 5, 7, 11 ,13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97, 101, 107};

    vector<vector<string>> helper(vector<string> &s) {
        unordered_map<string, vector<string>> alpha; 
        
        // vector <long long int> hashes;
        vector<string> copy = s;
        
        vector<vector<string>> res; 
        
        int n = s.size(); 
        
        for(auto &word : copy) {
            sort(word.begin(), word.end());
            
        }
                
        for(int i = 0 ; i < n; i++) {
            alpha[copy[i]].push_back(s[i]);
        }
        
        for(auto i : alpha){
            res.push_back(i.second);
        }
        
        return res;
    }
};