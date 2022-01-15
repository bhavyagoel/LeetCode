// { Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

 // } Driver Code Ends
class Solution
{
public:
    vector<int> subsetSums(vector<int> arr, int N)
    {
        // Write Your Code here
        subsets(0, 0, arr, N);
        return res; 
    }
    
private:
    vector<int> res; 
    
    void subsets(int idx, int s, vector<int>&arr, int N) {
        if(idx==N) {
            res.push_back(s);
            return;
        }
        
        s += arr[idx]; 
        subsets(idx+1, s, arr, N);
        s -= arr[idx]; 
        subsets(idx+1, s, arr, N);
        return;
    }
};

// { Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N;
        cin>>N;
        vector<int> arr(N);
        for(int i = 0 ; i < N ; i++){
            cin >> arr[i];
        }
        Solution ob;
        vector<int> ans = ob.subsetSums(arr,N);
        sort(ans.begin(),ans.end());
        for(auto sum : ans){
            cout<< sum<<" ";
        }
        cout<<endl;
    }
    return 0;
}  // } Driver Code Ends