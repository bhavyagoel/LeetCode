class Solution {
public:
    
    void recursiveRev(vector<char> &arr, int i , int j) {
        if(i>j) {
            return ;
        }
        
        swap(arr[i], arr[j]); 
        return recursiveRev(arr, ++i, --j);
    }
    
    void reverseString(vector<char>& s) {
        
        int n = s.size(); 
        
        recursiveRev(s, 0, n-1);
    }
};