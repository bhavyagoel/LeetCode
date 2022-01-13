// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
  public:
  
    static bool compare(pair<int, int> &p1, pair<int, int> &p2)
    {
        // if frequencies of two elements are same
        // then the larger number should come first
        if (p1.second == p2.second)
        return p1.first > p2.first;
        
        // sort on the basis of decreasing order
        // of frequencies
        return p1.second > p2.second;
    }


  
    vector<int> topK(vector<int>& arr, int k) {
        // Code here
        
        int n = arr.size();
        unordered_map<int, int> um;
        for (int i = 0; i < n; i++)
        um[arr[i]]++;
        
        // store the elements of 'um' in the vector 'freq_arr'
        vector<pair<int, int> > freq_arr(um.begin(), um.end());
        
        // sort the vector 'freq_arr' on the basis of the
        // 'compare' function
        sort(freq_arr.begin(), freq_arr.end(), compare);
        vector<int> res;
        for (int i = 0; i < k; i++) {
            res.push_back(freq_arr[i].first);
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