// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//Function to determine if graph can be coloured with at most M colours such
//that no two adjacent vertices of graph are coloured with same colour.
bool isSafe(bool graph[101][101], int node, int col[], int n, int color) {
    for(int i = 0; i < n; i++) {
        if(i!=node and graph[i][node]==1 and col[i]==color) {
            return false;
        }
    }
    return true;
}

bool checkCol(int col[], bool graph[101][101], int node, int m, int n) {
    if(node == n) {
        return true; 
    }
    
    for(int i = 1; i <= m ; i++) {
        if (isSafe(graph, node, col, n, i)) {
            col[node] = i;
            if(checkCol(col, graph, node+1, m, n)) return true;
            col[node] = 0;
        }
    }
    
    return false; 
}

bool graphColoring(bool graph[101][101], int m, int V)
{
    // your code here
    int col[V] = {0};
    return checkCol(col, graph, 0, m, V);
}

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m, e;
        cin >> n >> m >> e;
        int i;
        bool graph[101][101];
        for (i = 0; i < n; i++) {
            memset(graph[i], 0, sizeof(graph[i]));
        }
        for (i = 0; i < e; i++) {
            int a, b;
            cin >> a >> b;
            graph[a - 1][b - 1] = 1;
            graph[b - 1][a - 1] = 1;
        }
        cout << graphColoring(graph, m, n) << endl;
    }
    return 0;
}
  // } Driver Code Ends