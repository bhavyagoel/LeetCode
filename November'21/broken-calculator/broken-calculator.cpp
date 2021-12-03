class Solution {
public:
    int brokenCalc(int startValue, int target) {
        if(target<=startValue) {
            return startValue-target;
        }else {
            int steps = 0; 
            while(target>startValue) {
                steps = target%2?steps+2:steps+1;
                target = target%2?target+1:target;
                target = target/2;
            }
            return steps + (startValue-target); 
        }
    }
};