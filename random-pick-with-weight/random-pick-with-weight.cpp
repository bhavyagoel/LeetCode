class Solution {
public:
    vector<int> a;
    Solution(vector<int>& w) {
        a.push_back(w[0]);
        for(int i = 1; i < w.size(); i++) {
            a.push_back(w[i]+a.back());
        }
    }
    
    int pickIndex() {
        int num = a.back();
        int idx = rand()%num; 
        auto it = upper_bound(a.begin(), a.end(), idx);
        return it - a.begin();
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(w);
 * int param_1 = obj->pickIndex();
 */