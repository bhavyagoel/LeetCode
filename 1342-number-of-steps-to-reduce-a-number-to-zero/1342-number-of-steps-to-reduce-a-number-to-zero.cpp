class Solution {
public:
    int numberOfSteps(int num) {
        return num>0?floor(log(num)/log(2)) + __builtin_popcount(num): 0;
    }
};