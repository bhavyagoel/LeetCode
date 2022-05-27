class Solution {
public:
    int minMoves(int target, int maxDoubles) {
        int res = 0; 
        while(maxDoubles and target!=0) {
            if(target%2 or !maxDoubles) {
                res++;
                target--;
            }else{
                target /= 2;
                res++;
                maxDoubles--;
            }
        }
        
        return res+target-1;
    }
};