class Solution {
public:
    vector<int> recoverArray(vector<int>& nums) {
        int n = nums.size(); 
        if(n==2) return {(nums[0]+nums[1])/2};
        sort(nums.begin(), nums.end()); 
        
        set<int> lower; 
        for(int i = 1; i < n; i++) {
            if((nums[i]-nums[0])%2==0 and nums[i]!=nums[0]) lower.insert((nums[i]-nums[0])/2);
        }
                
        unordered_map<int, int> temp; 
        for(int i = 0; i < n; i++) {
            temp[nums[i]]++;
        }
        
        unordered_map<int, int> check; 
        for(auto &it : lower) {
            int low = it; 
            
            vector<int> res; 
            int size = 4;
            
            check = temp; 
            
            res.push_back(nums[0]+low);
            check[nums[0]]--;
            check[nums[0]+2*low]--; 
            
            
            res.push_back(nums[n-1]-low);
            check[nums[n-1]]--;
            
            if(!check[nums[n-1]-2*low]) continue; 
            
            check[nums[n-1]-2*low]--;

            for(int i = 0; i < n; i++) {
                
                if(!check[nums[i]]) continue; 
                
                if(check[nums[i]+2*low]) {
                    res.push_back(nums[i]+low);
                    check[nums[i]]--;
                    check[nums[i]+2*low]--;
                    size += 2;
                }

                else if(check[nums[i]-2*low]){
                    res.push_back(nums[i]-low);
                    check[nums[i]]--;
                    check[nums[i]-2*low]--;
                    size += 2;
                }

            }       
            if(size == n) {
                return res; 
            }
        }
        
        return {}; 
    }
};