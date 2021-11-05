class Solution {
public:
    int findNumbers(vector<int>& nums) {
        int res  =  0;
        for(auto i : nums){
            int count = 0; 
            while(i){
                count++; 
                i = i/10; 
            }
            res = count%2?res:res+1;
        }
        
        return res; 
    }
};