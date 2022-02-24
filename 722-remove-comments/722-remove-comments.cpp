class Solution {
public:
    vector<string> removeComments(vector<string>& source) {
        vector<string> res; 
        bool block = false; 
        string temp = "";
        for(auto line : source) {
            for(int start = 0; start < line.size(); start++) {
                if(!block and line[start]=='/' and start+1 != line.size() and line[start+1]=='/') break;
                else if(!block and line[start]=='/' and start+1 != line.size() and line[start+1]=='*') {
                    block = true; 
                    start++;
                }                
                else if(block and line[start]=='*' and start+1 != line.size() and line[start+1]=='/') {
                    block = false; 
                    start++;
                }
                else if(!block) temp += line[start];
            }
            if(temp.size() and !block) res.push_back(temp), temp.clear();
            
        }
        return res;         
    }
};