class Solution {
public:
    vector<int> findOriginalArray(vector<int>& changed) {
        vector<int> res; 
        unordered_map <int, int> alpha;
        
        for(auto i : changed) {
            alpha[i] +=1;
        }
        sort(changed.begin(), changed.end());
        for(auto i : changed) {
            if(i != 0) {
                if(alpha[2*i] != 0 && alpha[i] != 0) {
                    // cout<<i<<" "<<2*i<<endl;
                    alpha[2*i]--;
                    alpha[i]--;
                    res.push_back(i);
                }
            }
            else {
                if(alpha[i]%2 == 0 && alpha[i] != 0) {
                    res.push_back(i);
                    alpha[i] -= 2;
                }
            }
            
        }
        
        if((2*res.size()) == changed.size()) {
            return res; 
        }     
        
        return {};
        
        
    }
};