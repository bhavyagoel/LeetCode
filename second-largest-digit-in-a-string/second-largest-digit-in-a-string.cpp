class Solution {
public:
    int secondHighest(string s) {
        int max = -1;
        int second_max = -1;
        for(auto i : s) {
            if(!isalpha(i)) {
                int num = i - '0'; 
                
                if(max < num) {
                    second_max = max;
                    max = num;
                }
                
                else if(num > second_max && num != max){
                    second_max = num; 
                }
                
            }
        }
        return second_max;
    }
};