class Solution {
public:
    int clumsy(int n) {
        if(n<3) return n; 
        
        stack<int> temp; 
        int cnt = 0; 
        while(n) {
            int curr;
            if(n>=3) {
                if(cnt==0) curr = (n*(n-1))/(n-2);
                else curr = (-n*(n-1))/(n-2);
                temp.push(curr);
                n-=3;
                cnt+=1;
            }
            
            if(n>=1){
                curr = n;
                temp.push(curr);
                n -= 1;
            }
            
            if(n==2) {
                curr = -n*(n-1);
                temp.push(curr);
                n -= 2;
            }
            
            if(n==1){
                curr = -n;
                temp.push(curr);
                n -= 1;
            }
        }
        
        int res = 0; 
        while(!temp.empty()) {
            res += temp.top(); 
            temp.pop();
        }
        return res;
    }
};