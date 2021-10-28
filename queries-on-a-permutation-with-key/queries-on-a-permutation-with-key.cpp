class Solution {
public:
    vector<int> processQueries(vector<int>& queries, int m) {
        
        vector<int> res;
        
        map<int, int> nums; 
        for(int i = 0 ; i < m; i++) {
            nums[i+1] = i;
        }
        
        for(int i = 0; i < queries.size(); i++){
            res.push_back(nums[queries[i]]);
            
            for(int j = 1; j <= m; j++) {
                if(nums[j] < nums[queries[i]]) {
                    nums[j] += 1;
                }
            }
            nums[queries[i]] = 0;
        }
        
        return res;
    }
};