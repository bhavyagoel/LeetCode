class Solution {
public:
    vector<string> generateParenthesis(int n) {
        string s;
        backtrack(s, n, 0, 0);
        return res;
    }
    
private:
    vector<string> res;
    
    void backtrack(string &s, int n, int open, int close) {
        if (s.length() == 2*n) {
            res.push_back(s);
            return;
        }
        
        if(open<n) {
            s.push_back('(');
            backtrack(s, n, open+1, close);
            s.pop_back();
        }
        if(close<open) {
            s.push_back(')');
            backtrack(s, n, open, close+1);
            s.pop_back();
        }
        
        return;
    }
};