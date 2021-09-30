class Solution {
public:
    bool check(string &a, int i, int j) {
        while( i<j && a[i] == a[j]) {
            ++i;
            --j;
        }
        return i>=j;
    }
    
    bool checkPalind(string &a, string &b) {
        int i = 0; 
        int j = a.size() -1; 
        while(i<j && a[i] == b[j]) {
            ++i;
            --j;
        }
        return check(a, i, j) || check(b, i, j);
    }
    bool checkPalindromeFormation(string a, string b) {
        return checkPalind(a, b) || checkPalind(b, a);
    }
};