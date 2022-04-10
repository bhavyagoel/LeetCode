class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        stack<int> check; 
        int n = pushed.size(), i = 0, j = 0; 
        
        while(i<n or j<n) {
            if(i>=n) {
                if(check.empty()) return false; 
                if(check.top()!= popped[j]) {
                    return false; 
                }
                else {
                    j++;
                    check.pop(); 
                }
            }
            else if(j>=n) {
                check.push(pushed[i]); 
                i++;
            }
            else {
                if(!check.empty() and check.top() == popped[j]) {
                    check.pop(); 
                    j++;
                    continue;
                }
                check.push(pushed[i]);
                i++;
            }
        }
        return true; 
    
    }
};