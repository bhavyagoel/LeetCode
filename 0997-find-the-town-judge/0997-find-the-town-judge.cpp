class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        vector<int> a(n, 0);
        vector<int> b(n, 0);
        for (auto& t : trust) {
            ++a[t[0] - 1];
            ++b[t[1] - 1];
        }
        for (int i = 0; i < n; ++i) {
            if ((a[i] == 0) && (b[i] == (n - 1))) return (i + 1);
        }
        return -1;
    }
};