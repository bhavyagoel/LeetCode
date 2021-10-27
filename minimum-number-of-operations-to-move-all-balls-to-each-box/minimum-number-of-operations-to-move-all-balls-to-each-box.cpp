class Solution {
public:
    vector<int> minOperations(string boxes) {
        vector<int> ones; 
        
        for(int i = 0 ; i < boxes.length(); i++) {
            if(boxes[i] == '1') {
                ones.push_back(i);
            }
        }
        
        vector<int> res;
        for(int i = 0; i < boxes.length(); i++) {
            int count = 0; 
            for(auto j : ones){
                count += abs(j - i);
            }
            res.push_back(count);
        }
        
        return res; 
    }
};