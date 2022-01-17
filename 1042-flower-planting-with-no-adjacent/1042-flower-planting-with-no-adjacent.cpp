class Solution {
public:
    vector<int> gardenNoAdj(int n, vector<vector<int>>& paths) {
        
        unordered_map<int, vector<int>> adj;                
        for(int i = 0; i < paths.size(); i++) {
            adj[paths[i][0]-1].push_back(paths[i][1]-1);
            adj[paths[i][1]-1].push_back(paths[i][0]-1);

            
        }
        vector<int> col(n, 0);
        checkGarden(adj, col, n, 0);
        
        return res;
    }
    
private:
    bool isSafe(unordered_map<int, vector<int>>& adj, int node, vector<int>& col, int color, int n) {
        for(int adjNodes : adj[node]) {
            if (col[adjNodes]==color) {
                return false;
            }
        }
        
        return true;
    }
    
    vector<int> res;
    bool checkGarden(unordered_map<int, vector<int>>& adj, vector<int>& col, int n, int node) {
        
        if(node==n) {
            return true;
        }
        
        for(int i = 1; i <= 4; i++) {
            if(isSafe(adj, node, col, i, n)) {
                res.push_back(i);
                col[node] = i;
                if(checkGarden(adj, col, n, node+1)) return true;
                col[node] = 0;
                res.pop_back();
            }
        }
        return false;
    }
};