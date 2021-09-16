class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        map<int, int> check; 
        
        for(auto i : nums) {
            if(check[i] != 0) {
                return true;
            }
            check[i] = 1;
        }
        
        return false;
    }
};