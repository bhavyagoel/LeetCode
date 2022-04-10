class Solution {
public:
    int minOperations(vector<string>& logs) {
        stack<string> temp; 
        
        for(auto it : logs) {
            if(it=="../") {
                if(!temp.empty()) temp.pop(); 
            }
            else if(it=="./") continue;
            else if(it.back()=='/') {
                it.pop_back(); 
                temp.push(it); 
            }
        }
        
        return temp.size(); 
    }
};