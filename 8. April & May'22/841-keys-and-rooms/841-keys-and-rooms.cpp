class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n = rooms.size(); 
        vector<int> check(n, 0);         
        
        queue<int> q;
        
        check[0] = 1; 
        q.push(0); 

        while(!q.empty()) {
            int n = q.size(); 
            while(n--) {
                int tmp = q.front(); 
                q.pop(); 
                for(auto it : rooms[tmp]) {
                    if(!check[it]) q.push(it);
                    check[it] = 1; 
                }
            }
        }
        
        for(int i = 0; i < n; i++) {
            if (check[i]==0) {
                return false;
            }
        }
        return true; 
    }
};