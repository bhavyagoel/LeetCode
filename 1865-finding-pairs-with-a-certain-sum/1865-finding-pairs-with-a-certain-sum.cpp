class FindSumPairs {
public:
    FindSumPairs(vector<int>& _num1, vector<int>& _num2) {
        _n1 = _num1;
        _n2 = _num2;
    
        for(auto &it : _num2) {
            n2[it]++;
        }
    }
    
    void add(int i, int val) {
        n2[_n2[i]]--;
        _n2[i] += val;
        n2[_n2[i]]++;
    }
    
    int count(int tot) {
        int cnt = 0;
        for(auto &it : _n1) {
            cnt += n2[tot-it];            
        }
        return cnt;
    }
private:
    unordered_map<int, int> n2; 
    vector<int> _n1; 
    vector<int> _n2;
};

/**
 * Your FindSumPairs object will be instantiated and called as such:
 * FindSumPairs* obj = new FindSumPairs(nums1, nums2);
 * obj->add(index,val);
 * int param_2 = obj->count(tot);
 */