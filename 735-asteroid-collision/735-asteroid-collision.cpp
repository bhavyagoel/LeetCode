class Solution {
public:
    vector<int> asteroidCollision(vector<int>& a) {
        stack<int> stk; 
        
        int i = 0, n = a.size(); 
        while(i<n) {
            if(stk.size()==0) {
                stk.push(a[i]);
                i++;
                continue; 
            }
            
        
            int curr = a[i]; 
            int top = stk.top(); 
            if(curr*top > 0) {
                stk.push(curr);
            }else {

                if(curr>top){
                    stk.push(curr);
                }
                else if (mod(curr)==top) {
                    stk.pop();
                }
                else {
                    if(mod(curr)>top){
                        while(!stk.empty() and stk.top()*curr<0 and stk.top()<=mod(curr)){
                            if(stk.top()==mod(curr)) {
                                stk.pop(); 
                                curr = 0; 
                                break;
                            }
                            stk.pop();
                        }
                        if ((stk.empty() or curr*stk.top()>0) and curr!=0) stk.push(curr);
                    }
                }
            }
            
            i++;
        }
        
        vector<int> res; 
        while(!stk.empty()) {
            res.push_back(stk.top()); 
            stk.pop();
        }

        reverse(res.begin(), res.end());
        return res;
    }
    
private:
    int mod(int n){
        return n<0?n*-1:n;
    }
};