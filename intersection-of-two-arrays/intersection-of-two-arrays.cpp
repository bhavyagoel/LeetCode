class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        vector<int> ans; 
        
        map<int,int> vals1;
        map<int, int> vals2;
        
        int n1 = nums1.size(); 
        int n2 = nums2.size(); 
        
        for(int i = 0 ; i < n1; i++) {
            vals1[nums1[i]] += 1;
        }
        
        for(int i = 0; i < n2; i++) {
            vals2[nums2[i]] += 1;
        }
        
        
        for(auto i : vals2) {
            if(vals1[i.first] != 0) {
                ans.push_back(i.first);
            }
        }
    
        return ans;
    }
};
