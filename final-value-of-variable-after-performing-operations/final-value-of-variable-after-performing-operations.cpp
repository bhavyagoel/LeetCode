class Solution {
public:
    int finalValueAfterOperations(vector<string>& operations) {
        
        int res = 0; 
        
        for(auto i : operations) {
            if(i=="--X" || i=="X--") {
                res-=1;
            }
            else {
                res+=1;
            }
        }
        
        return res;
    }
};