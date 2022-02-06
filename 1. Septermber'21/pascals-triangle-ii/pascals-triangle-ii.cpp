typedef long long int ll;

class Solution {
public:
    vector<int> getRow(int rowIndex) {
        
        vector<int> res; 
        int i = 1; 
        while(i <= rowIndex+1) {
            int j = 1;
            ll num = 1; 
            while(j<=i) {
                if(i == rowIndex+1){
                    res.push_back(num);
                }
                
                num *= (i-j);
                num /= j;
                j++;
            }

            i++;
        }

        return res; 
        
    }
};