class Solution {
public:
    int maxDistToClosest(vector<int>& seats) {
        int n = seats.size(); 
        int prev = 0; 
        int res = 0; 
        
        int strt = 0, lst = n-1; 
        
        if(seats[strt]==0) {
            while (seats[strt] != 1) {
                strt++;
            }

            res = max(res, strt);
        }
        
        if (seats[lst]==0) {
            while(seats[lst] != 1) {
                lst--;
            }
            
            res = max(res, (n-lst-1));
        }
        
        
        for(int i = strt ; i <= lst; i++) {
            if (seats[i]==1) {
                int diff = (i - prev)/2; 
                res = max(res, diff);
                prev = i;
            }
        }
        
        return res; 
    }
};