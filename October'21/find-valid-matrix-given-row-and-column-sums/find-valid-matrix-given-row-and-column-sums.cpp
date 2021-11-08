class Solution {
public:
    /*vector<vector<int>> restoreMatrix(vector<int>& rs, vector<int>& cs) {
        vector<vector<int>> m(rs.size(), vector<int>(cs.size()));
        for (int x = 0; x < rs.size(); ++x)
            for (int y = 0; y < cs.size() && rs[x] > 0; ++y) {
                m[x][y] = min(rs[x], cs[y]);
                rs[x] -= m[x][y];
                cs[y] -= m[x][y];
            }
        return m;
    }*/
    
    
    vector<vector<int>> restoreMatrix(vector<int>& rs, vector<int>& cs) {
        vector<vector<int>> m(rs.size(), vector<int>(cs.size()));
        for (int x = 0, y = 0; x < rs.size() && y < cs.size(); ) {
            m[x][y] = min(rs[x], cs[y]);
            rs[x] -= m[x][y];
            cs[y] -= m[x][y];
            x += rs[x] == 0;
            y += cs[y] == 0;
        }
        return m;
    }


};