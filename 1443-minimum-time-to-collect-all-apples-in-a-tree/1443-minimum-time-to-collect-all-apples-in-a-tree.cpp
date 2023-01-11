class Solution {
public:
    
    int dfs(map<int, vector<int>>& adj, int node, int parent, vector<bool>& hasApple){
                
        int totalTime = 0, childTime = 0; 
        for(auto child : adj[node]){
            if(child == parent) continue; // this stops the dfs to go back to top and keep going down in tree
            childTime = dfs(adj, child, node, hasApple);
            
            if(childTime || hasApple[child]) totalTime += childTime + 2;
        }
        
        return totalTime; 
    }
    
    int minTime(int n, vector<vector<int>>& edges, vector<bool>& hasApple) {
        map<int, vector<int>> adj; 
        
        for(auto &it : edges) {
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        
        return dfs(adj, 0, -1, hasApple);
        
        
    }
};