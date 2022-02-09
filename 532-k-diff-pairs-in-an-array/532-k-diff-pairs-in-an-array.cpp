class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        unordered_map<int, int> temp; 
        sort(nums.begin(), nums.end()); 
        for(auto it : nums) cout<<it<<" ";
        cout<<endl;
        
        int n = nums.size(); 
        int res = 0; 
        if(k==0){
            for(int i = 0; i < n; i++) {
                int num = nums[i]; 
                if(temp[num]) {
                    res += 1;
                    
                    while(i<n and num == nums[i]) i++;
                    i--;
                }
                temp[num] = 1;
            }
        }
        else {
            for(int i = 0; i < n; i++) {
                int num = nums[i]; 
                int check = k + num; 
                res += temp[check];
                if(temp[check]) temp[check]--;

                check = num-k;
                res += temp[check];
                if(temp[check]) temp[check]--;

                temp[num] = 1;            
            }
        }
        
        
        return res; 
    }
};