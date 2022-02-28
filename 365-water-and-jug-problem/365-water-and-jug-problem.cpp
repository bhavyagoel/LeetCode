// https://leetcode.com/problems/water-and-jug-problem/discuss/83727/c%2B%2B-solution-follow-the-procedure

class Solution {
public:
    bool canMeasureWater(int x, int y, int z) {
        if (x+y == z)
            return true;
        if (x+y < z)
            return false;
        if (x > y) {
            swap(x, y);
        }
        int volume = 0;
        while (1) {
            if (volume < x)
                volume += y;
            else
                volume -= x;
            if (volume == z)
                return true;
            if (volume == 0)
                return false;
        }
    }
};
/*
class Solution {
public:
    bool canMeasureWater(int j1, int j2, int tgt) {
        queue<pair<int, int>> temp; 
        
        map<pair<int,int>, bool> visited; 
        temp.push({0,0});
        visited[{0,0}] = true;
        while(!temp.empty()) {
            
            int k = temp.size(); 
            int tempA, tempB; 
            while(k--){
                int a = temp.front().first; 
                int b = temp.front().second; 
                if(a==tgt) return true; 
                if(b==tgt) return true; 
                if(a+b == tgt) return true; 
                
                temp.pop(); 
                
                // 4 operations 
                // fill first 
                if(!visited[{j1,b}]) {
                    temp.push({j1,b});
                    visited[{j1,b}] = true; 
                }
                
                // fill second
                if(!visited[{a,j2}]) {
                    temp.push({a,j2});
                    visited[{a,j2}] = true; 
                }
                
                // empty first
                if(!visited[{0,b}]) {
                    temp.push({0,b});
                    visited[{0,b}] = true; 
                }
                
                // empty second
                if(!visited[{a,0}]) {
                    temp.push({a,0});
                    visited[{a,0}] = true; 
                }
                
                // transfer first
                tempB = tempB + a > j2 ? j2 : tempB + a;
                tempA = j2 - b < a ? a - (j2-b) : 0;
                if(!visited[{tempA,tempB}]) {
                    temp.push({tempA, tempB});
                    visited[{tempA, tempB}] = true; 
                }
                
                // transfer second 
                tempA = tempA + b > j1 ? j1 : tempA + b; 
                tempB = j1 - a < b ? b - (j1-a) : 0;
                if(!visited[{tempA, tempB}]) {
                    temp.push({tempA, tempB});
                    visited[{tempA, tempB}] = true; 
                }
            }            
        }
        
        return false; 
        
    }
};
*/