class Solution {
public:
    bool canReorderDoubled(vector<int>& arr) {
        unordered_map<int, int> temp; 
        sort(arr.begin(), arr.end()); 
        
        for(auto& it : arr) temp[it]++; 
        
        int size = 0; 
        for(auto& it : arr) {
            if(it==0){
                if(temp[it]>=2) {
                    size += 2; 
                    temp[it]--; 
                    temp[2*it]--; 
                }
            }
            else if(temp[it] and temp[2*it]) {
                size += 2; 
                temp[it]--; 
                temp[2*it]--; 
            }
        }
        return size == arr.size(); 
    }
};