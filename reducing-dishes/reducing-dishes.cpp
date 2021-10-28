class Solution {
public:
    int maxSatisfaction(vector<int>& satisfaction) {        
        sort(satisfaction.begin(), satisfaction.end()); 

        int sum = 0; 
        int i = satisfaction.size(); 
        while(i--){
            sum += satisfaction[i]; 
            if(sum<=0){
                i+=1;
                break;
            }
        }
        i = sum<=0?i:0;
        
        int res = 0; 
        int j = 1;
        for(int pos = i; pos < satisfaction.size(); pos++){
            res += j*satisfaction[pos];
            j++;
        }
        
        return res; 
    }
};