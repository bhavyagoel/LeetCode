class Solution {
public:    
    int subarraySum(vector<int>& arr, int k) {
        unordered_map <int, int> map;
        int count = 0;
        int currsum = 0;
        map[0]++;
        for(auto i : arr) {
            currsum += i;
            
            count += map[currsum - k];
            map[currsum] ++;           
        }
        
        return count; 
    }
};