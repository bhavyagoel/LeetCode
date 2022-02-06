class Solution {
public:
    vector<int> numSmallerByFrequency(vector<string>& queries, vector<string>& words) {
        int m = queries.size(); 
        int n = words.size(); 
        
        
        vector<int> q(m, 0); 
        vector<int> w(n, 0);
        
        for(int i = 0; i < m; i++) {
            int arr[26] = {0};
            char smallest = 'z';
            int len = queries[i].length(); 
            for(int j = 0; j < len; j++) {
                arr[queries[i][j]-'a']+=1;
                if(smallest > queries[i][j]) {
                    smallest = queries[i][j];
                }
            }
            q[i] = arr[smallest-'a'];
        }
        
        for(int i = 0; i < n; i++) {
            int arr[26] = {0};
            char smallest = 'z';
            int len = words[i].length(); 
            for(int j = 0; j < len; j++) {
                arr[words[i][j]-'a']+=1;
                if(smallest > words[i][j]) {
                    smallest = words[i][j];
                }
            }
            w[i] = arr[smallest-'a'];
        }
        
        sort(w.begin(), w.end()); 
        vector<int> res;
        
        for(int i = 0; i < q.size(); i++) {
            int len = w.size();
            int lo = 0; 
            int hi = len-1; 
            
            while(lo<=hi) {
                int mid = (hi+lo)/2; 
                
                if(w[mid]<=q[i]) {
                    lo = mid+1; 
                }else hi = mid-1; 
            }
            res.push_back(len-lo);
        }
        
        return res;
    }
};