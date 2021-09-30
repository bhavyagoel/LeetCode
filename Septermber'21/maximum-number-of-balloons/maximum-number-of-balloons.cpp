class Solution {
public:
    int maxNumberOfBalloons(string text) {
        
        
        map<char, int> alpha;
        int n = text.size(); 
        
        for(auto &i : text){
            i = tolower(i);
        }
        
        for(int i = 0 ; i < n; i++) {
            alpha[text[i]] += 1;
        }
        
        string search = "balloon";
        
        int min = INT_MAX; 
        
        for(auto i : search) {
            if (alpha[i] < min) {
                min = alpha[i];
            }
        }
        
        for(int i = min; i > 0; i--) {
            if(alpha['l'] >= 2*i && alpha['o'] >= 2*i){
                return i;
            }
        }
        
        return 0;
    }
};