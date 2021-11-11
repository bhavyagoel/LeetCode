class Solution {
public:
    int minStartValue(vector<int>& nums) {
        int pre = 0 , minAns=0;
        for(int it : nums){
            pre += it;
            if(pre < minAns)
                minAns = pre;
        }
        return -minAns+1;
    }   
};