// Copied

class Solution {
public:
    vector<int> findOrder(int N, vector<vector<int>>& P) {
        vector<vector<int>> G(N);                   // {prerequisite-course : [list of next courses]}
        vector<int> ans, indegree(N);               // indegree[i] denotes number of prerequisite courses for ith course
        for(auto& pre : P) 
            G[pre[1]].push_back(pre[0]),            // forming adjacency list graph
            indegree[pre[0]]++;                     
        
        queue<int> q;
        for(int i = 0; i < N; i++)
            if(indegree[i] == 0) q.push(i);         // we can start with courses having no prequisites
        
        while(size(q)) {
            auto cur = q.front(); q.pop();
            ans.push_back(cur);                     // cur has no remaining pre courses, so we can take it now
            for(auto nextCourse : G[cur]) 
                if(--indegree[nextCourse] == 0)     // if there's a next course having 0 prequisite remaining,
                    q.push(nextCourse);             // then we can take it
        }
        if(size(ans) == N) return ans;              // ordering exists where all courses can be finished
        return {};                                      
    }
};
