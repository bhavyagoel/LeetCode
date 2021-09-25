// https://leetcode.com/problems/kth-smallest-element-in-a-sorted-matrix/discuss/85173/Share-my-thoughts-and-Clean-Java-Code



class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        return helper_binarySeach(matrix, k);
    }
    
private:
    int helper_priorityQueue(vector<vector<int>> &matrix, int &k) {
        vector<int> res;
        int n = matrix.size(); 
        map<int, int> alpha; 
        
        for(int i = 0; i <n; i++) {            
            for(int j = 0; j<n; j++) {
                alpha[matrix[i][j]] += 1;
            }
        }
        int count = 0;
        int val; 
        for(auto i : alpha){
            count += i.second;
            if(count >= k) {
                val = i.first;
                break;
            }
        }
        return val;
    }
    
    
    int helper_binarySeach(vector<vector<int>> &matrix, int &k) {
        
        int n = matrix.size(); 
        
        int lo = matrix[0][0]; 
        int hi = matrix[n-1][n-1]; 
        
        while(lo<=hi) {
            int mid = lo + (hi - lo)/2;
            int count = getLessEqual(matrix, mid);
            
            if(count < k) lo = mid+1; 
            else hi = mid-1;
        }
        cout<<lo<<" "<<hi<<endl;
        return lo;
    }
    
    int getLessEqual(vector<vector<int>> &matrix, int &val) {
        
        int i = matrix.size()-1; 
        int j = 0; 
        int count = 0; 
        
        while(i>-1 && j<matrix.size()) {
            if(matrix[i][j] > val) i--;
            
            else {
                j++;
                count += i+1;
            }
        }
        return count; 
        
    }
};