class Solution {
public:
    
    vector<int> dfs(map<int, vector<int>>& adj, string &labels, int node, int parent, vector<int> &res ){
        
        vector<int> count(26,0);
        count[labels[node]-'a']++;
        for(auto curr : adj[node]){
            if(curr == parent) continue;
            vector<int> tmp = dfs(adj, labels, curr, node, res);
            
            for(int i = 0; i < 26; i++)
                count[i]+=tmp[i];
            
        }
        
        res[node] += count[labels[node]-'a'];
        return count;
    }
    
    
    vector<int> countSubTrees(int n, vector<vector<int>>& edges, string labels) {
        map<int, vector<int>> adj; 
        for(auto it : edges){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        
        vector<int> res(n, 0);        
        dfs(adj, labels, 0, -1, res);

        return res; 
        
    }
};