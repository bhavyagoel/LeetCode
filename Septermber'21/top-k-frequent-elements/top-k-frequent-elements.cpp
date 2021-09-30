class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        return helper(nums, k);
    }
    
private:
    vector<int> helper(vector<int>& nums, int &k) {
        unordered_map<int, int> temp; 
        vector<int> res;
        for(auto i : nums) {
            temp[i]++;
        }
        
        multimap<int, int, greater <int>> temp_; 
        for(auto i : temp) {
            temp_.insert(make_pair(i.second, i.first));
        }
        
        
        for(auto i : temp_) {
            if (k>0) {
                res.push_back(i.second);
                k--;
            }else{
                break;
            }
        }
        
        return res;
    }
};