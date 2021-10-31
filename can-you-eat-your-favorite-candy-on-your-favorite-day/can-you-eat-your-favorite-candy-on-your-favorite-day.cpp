class Solution {
public:
    vector<bool> canEat(vector<int>& cc, vector<vector<int>>& queries) {
        vector<bool> res; 
        
        vector<long long int> temp(cc.size(), 0); 
        temp[0] = cc[0];
        for(int i = 1 ; i < cc.size(); i++){
            temp[i] = cc[i] + temp[i-1];
        }
        
        for(auto &q : queries) {
            int type = q[0];
            int day = q[1]; 
            int cap = q[2];
            
            if(type==0){
                bool val = day<temp[type]?true:false;
                res.push_back(val);
                continue;
            }
            
            long long int earliest = temp[type-1]/cap;
            long long int latest = temp[type]-1;
            
            if(earliest<=day && day<=latest) res.push_back(true);
            else res.push_back(false);
        }
        
        return res; 
    }
};
