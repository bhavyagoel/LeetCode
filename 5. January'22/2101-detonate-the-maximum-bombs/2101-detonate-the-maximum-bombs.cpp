// This is not a union find because, a bomb will detonate iff it's detonation area crosses the other bombs position and not on the basis of bomb detonation area coincide. 
// https://leetcode.com/problems/detonate-the-maximum-bombs/discuss/1623585/This-is-why-Union-Find-doesn't-work-for-this-problem-with-diagram

class Solution {
private:
    bool checkCoincide(int x1, int y1, int r1, int x2, int y2) {
        if ((long long)(x1 - x2) * (long long)(x1 - x2) + (long long)(y1 - y2) * (long long)(y1 - y2) <= (long long)r1*r1)
            return true;
        return false;
        }
public:
    int maximumDetonation(vector<vector<int>>& bombs) {
        
        int n = bombs.size(); 
        int res = 0; 
        for(int i = 0; i < n; i++) {
            
            queue<int> checkBomb;
            unordered_map<int, bool> checkVisited;
            int cnt = 0;
            
            checkBomb.push(i);
            while(!checkBomb.empty()) {
                int currSize = checkBomb.size(); 
                cnt += currSize;
                // cout<<cnt<<" "<<currSize<<endl;
                while(currSize--) {
                    int ind = checkBomb.front(); 
                    checkVisited[ind] = true; 
                    checkBomb.pop();

                    int x = bombs[ind][0];
                    int y = bombs[ind][1]; 
                    int r = bombs[ind][2]; 
                    for(int j = 0; j < n; j++) {
                        int x1 = bombs[j][0]; 
                        int y1 = bombs[j][1]; 

                        if(checkVisited[j]!=true and checkCoincide(x,y,r,x1,y1)) {
                            checkBomb.push(j); 
                            checkVisited[j]=true;
                        }
                    }
                }
                
            }
            
            res = max(res, cnt);
        }
        
        return res; 
    }
};