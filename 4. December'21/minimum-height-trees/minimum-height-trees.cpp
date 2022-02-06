// COPIED


class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
    if(n == 1) return {0};
    vector<set<int>> adj(n);
    for(auto it:edges) {
        adj[it[0]].insert(it[1]);
        adj[it[1]].insert(it[0]);
    }
    vector<int> leaves;
    for(int i=0; i<n; i++) {
        if(adj[i].size() == 1)
            leaves.push_back(i);
    }
    while(leaves.size() < n) {
        n -= leaves.size();
        vector<int> newLeaves;
        for(auto x:leaves) {
            int y = *adj[x].begin();
            adj[y].erase(x);
            if(adj[y].size() == 1)
                newLeaves.push_back(y);
        }
        leaves = newLeaves;
    }
    return leaves;
}

};