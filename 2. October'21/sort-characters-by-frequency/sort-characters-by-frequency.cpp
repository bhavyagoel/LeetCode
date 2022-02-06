class Solution {
public:
    template <typename T1, typename T2>
    struct less_second {
        typedef pair<T1, T2> type;
        bool operator ()(type const& a, type const& b) const {
            return a.second > b.second;
        }
    };
    
    string frequencySort(string s) {
        unordered_map<char, int> alpha; 
        
        for(auto i : s){
            alpha[i] += 1;
        }

        s = "";
        
        vector<pair<char, int>> mapcopy(alpha.begin(), alpha.end());
        sort(mapcopy.begin(), mapcopy.end(), less_second<char, int>());

        
        for(auto i : mapcopy){
            for(int j = 0; j < i.second; j++) s += i.first;
        }
        
        return s;
    }
};