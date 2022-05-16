struct Pos{
    int x;
    int y;
    int val;

    Pos(int x, int y, int val) {
        this->x = x;
        this->y = y;
        this->val = val;
    }
};

class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {

        if(grid[0][0] != 0) return -1;

        map<pair<int, int>, bool> visited;
        queue<Pos*> temp;
        Pos* curr = new Pos(0, 0, 1);
        temp.push(curr);
        visited[{0,0}] = true;
        int res = INT_MAX;

        while(!temp.empty()) {
            int n = temp.size();

            while(n--) {

                curr = temp.front();
                int x = curr->x, y = curr->y, val = curr->val;
                
                temp.pop();

                if(x==grid.size()-1 and y==grid[0].size()-1) res = min(res, val);

                // Left
                if(x>0 and grid[x-1][y]==0 and !visited[{x-1, y}]) {
                    Pos* tmp = new Pos(x-1, y, val+1);
                    temp.push(tmp);
                    visited[{x-1,y}] = true; 
                }
                
                // Right
                if(x<grid.size()-1 and grid[x+1][y]==0 and !visited[{x+1,y}]) {
                    Pos* tmp = new Pos(x+1, y, val+1);
                    temp.push(tmp);
                    visited[{x+1,y}] = true; 
                }
                
                // Up
                if(y>0 and  grid[x][y-1] == 0 and !visited[{x,y-1}]) {
                    Pos* tmp = new Pos(x, y-1, val+1);
                    temp.push(tmp); 
                    visited[{x,y-1}] = true; 
                }
                
                // Down
                if(y<grid[0].size()-1 and grid[x][y+1]==0 and !visited[{x,y+1}]) {
                    Pos* tmp = new Pos(x, y+1, val+1);
                    temp.push(tmp); 
                    visited[{x,y+1}] = true; 
                }
                
                // Bottom Right
                if(x<grid.size()-1 and y<grid[0].size()-1 and grid[x+1][y+1]==0 and !visited[{x+1,y+1}]) {
                    Pos* tmp = new Pos(x+1, y+1, val+1);
                    temp.push(tmp); 
                    visited[{x+1,y+1}] = true; 
                }
                
                // Top Left
                if(x>0 and y>0 and grid[x-1][y-1]==0 and !visited[{x-1,y-1}]) {
                    Pos* tmp = new Pos(x-1, y-1, val+1);
                    temp.push(tmp); 
                    visited[{x-1,y-1}] = true; 
                }
                
                // Bottom Left
                if(x>0 and y<grid[0].size()-1 and grid[x-1][y+1]==0 and !visited[{x-1,y+1}]) {
                    Pos* tmp = new Pos(x-1, y+1, val+1);
                    temp.push(tmp); 
                    visited[{x-1,y+1}] = true; 
                }
                
                // Top Right
                if(x<grid.size()-1 and y>0 and grid[x+1][y-1]==0 and !visited[{x+1,y-1}]) {
                    Pos* tmp = new Pos(x+1, y-1, val+1);
                    temp.push(tmp); 
                    visited[{x+1,y-1}] = true; 
                }
                
                
                // Right
                // Up
                // Down
                // Top Right
                // Top Left
                // Bottom Right
                // Bottom Left
            }
        }
    return res==INT_MAX?-1:res;
    }
};
