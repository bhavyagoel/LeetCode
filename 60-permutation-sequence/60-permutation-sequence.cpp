class Solution {
public:
    string getPermutation(int n, int k) {
        string res;
        list<char> ds;
        factorial();
        for(char c = '1'; c < '1'+n; c++) {
            ds.push_back(c);
        }
        
        k -= 1; // For zero based indexing
        int remDigits = n-1;
        while(true) {
            if(ds.size()==1) {
                res.push_back(ds.back());
                break;
            }
            int pos = k/fact[remDigits];
            k = k%fact[remDigits];
            
            auto it = ds.begin();
            while(pos--) {
                it++;
            }
            res.push_back(*it);
            ds.erase(it);
            remDigits -= 1;
        }
        
        return res;
    }
    
private:
    vector<int> fact;
    void factorial() {
        fact.push_back(1);
        for(int i = 1; i <= 9; i++) {
            fact.push_back(i*fact[i-1]);
        }
        
        return;
    }
};