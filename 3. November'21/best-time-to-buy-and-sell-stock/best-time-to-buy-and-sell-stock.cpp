class Solution {
public:
    int maxProfit(vector<int>& prices) {
        
        int res = INT_MIN; 
        
        int mnBuy = INT_MAX; 
        for(int i = 0 ; i < prices.size(); i++) {
            mnBuy = min(mnBuy, prices[i]);
            res = max(res, (prices[i]-mnBuy));
        }
        
        return res;
    }
};