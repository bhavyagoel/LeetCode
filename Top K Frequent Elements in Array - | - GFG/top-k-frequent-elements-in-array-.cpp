// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
  public:
  
    static bool comp(pair<int, int>&a, pair<int, int> &b) {
        if(a.second == b.second) return a.first>b.first;
        return a.second>b.second; 
    }
  
    vector<int> topK(vector<int>& nums, int k) {
        // Code here
        
        sort(nums.begin(), nums.end());
        vector<pair<int, int>> topK; 
        
        int n = nums.size(); 
        for(int i = 0 ; i < n; i++) {
            int curr = nums[i];
            topK.push_back(make_pair(curr, 1));
            while(i+1<n and nums[i+1] == curr) {
                topK.back().second+=1;
                i++;
            }
        }
        
        sort(topK.begin(), topK.end(), comp);
        // for(int i = 0 ; i < topK.size(); i++) {
        //     cout<<topK[i].first<<" "<<topK[i].second<<endl;
        // }
        
       
        vector<int> res; 
        for(int i = 0 ; i < k; i++) {
            res.push_back(topK[i].first);
        }
        
        return res;
        
    }
};


// { Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n;
        cin >> n;
        vector<int> nums(n);
        for (auto &i : nums) cin >> i;
        int k;
        cin >> k;
        Solution obj;
        vector<int> ans = obj.topK(nums, k);
        for (auto i : ans) cout << i << " ";
        cout << "\n";
    }
    return 0;
}  // } Driver Code Ends