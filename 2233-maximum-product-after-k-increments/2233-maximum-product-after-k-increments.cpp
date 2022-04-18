class Solution {
public:
    int maximumProduct(vector<int>& nums, int k) {
        priority_queue <int, vector<int>, greater<int>> pq;
        
        for(auto &it : nums) {
            pq.push(it);
        }
        
        while(k--) {
            int tmp = pq.top(); 
            pq.pop(); 
            pq.push(tmp+1);
        }
        
        int mod = 1e9 + 7; 
        long long int res = 1; 
        
        while(!pq.empty()) {
            res *= pq.top();
            res %= mod; 
            pq.pop(); 
        }
        
        return res % mod; 
    }
};