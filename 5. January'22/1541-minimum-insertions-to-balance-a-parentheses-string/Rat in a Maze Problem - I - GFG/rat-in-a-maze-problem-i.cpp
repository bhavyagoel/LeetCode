// { Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
// User function template for C++

class Solution{
    public:
    vector<string> findPath(vector<vector<int>> &m, int n) {
        // Your code goes here
        vector<vector<bool>> visited(n, vector<bool>(n, false));
        string s; 
        visited[0][0] = true;
        if(m[0][0] == 1) allPath(m, visited, s, 0, 0, n);
        return res;
    }
    
    private:
    vector<string> res;
    
    void allPath(vector<vector<int>> &m, vector<vector<bool>> &visited, string &s, int row, int col, int n) {
        if(row==n-1 and col==n-1) {
            res.push_back(s);
            return;
        }
        
        // For lexicographical order
        // D|L|R|U
        
        // for D
        if (row < n-1 and !visited[row+1][col] and m[row+1][col] == 1 ) {
            visited[row+1][col] = true;
            s.push_back('D');
            allPath(m, visited, s, row+1, col, n);
            visited[row+1][col] = false;
            s.pop_back();
        }
        
        // for left
        if (col > 0 and !visited[row][col-1] and m[row][col-1] == 1 ) {
            visited[row][col-1] = true;
            s.push_back('L');
            allPath(m, visited, s, row, col-1, n);
            visited[row][col-1] = false;
            s.pop_back();
        }
        
        // for right
        if (col < n-1 and !visited[row][col+1] and m[row][col+1] == 1 ) {
            visited[row][col+1] = true; 
            s.push_back('R');
            allPath(m, visited, s, row, col+1, n);
            visited[row][col+1] = false;
            s.pop_back();
        }
        
        // for up
        if (row > 0 and !visited[row-1][col] and m[row-1][col] == 1 ) {
            visited[row-1][col] = true;
            s.push_back('U');
            allPath(m, visited, s, row-1, col, n);
            visited[row-1][col] = false;
            s.pop_back();
        }
        
        return;
    }
};

    


// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> m(n, vector<int> (n,0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> m[i][j];
            }
        }
        Solution obj;
        vector<string> result = obj.findPath(m, n);
        sort(result.begin(), result.end());
        if (result.size() == 0)
            cout << -1;
        else
            for (int i = 0; i < result.size(); i++) cout << result[i] << " ";
        cout << endl;
    }
    return 0;
}  // } Driver Code Ends