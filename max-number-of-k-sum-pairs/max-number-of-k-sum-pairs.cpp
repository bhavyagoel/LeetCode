class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        
        int n = nums.size(); 
        map<int, int> temp; 
        
        for(int i = 0; i < n; i++) {
            temp[nums[i]]++;
        }
        
        int res = 0;
        if (k%2==0 and temp[k/2]>=2) {
                int cases = temp[k/2]/2;
                while(temp[k/2] > 0 and cases > 0){
                    cases--;
                    temp[k/2]-=2; 
                    res+=1;
                }
            }
        for(auto it : temp) {
            if(it.second) {
                int tmp = k - it.first; 
                while (temp[tmp]>0 and tmp>it.first) {
                    temp[tmp]-=1;
                    it.second-=1;
                    res+=1;
                    if (temp[tmp]==0 or it.second==0) break;
                }
            }
        }
        return res;
    }
};