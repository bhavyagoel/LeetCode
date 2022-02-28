class Solution {
public:
    bool isValidSerialization(string pre) {
        stack<int> nums; 
        int n = pre.size(); 
        
        if(pre[0] != '#') nums.push(0);
        
        for(int i = 1; i < n; i++) {
            bool hash;
            if(pre[i]==',') continue;
            while(i<n and pre[i]!=',') {
                if(pre[i]=='#')hash = true;
                else hash = false;  
                i++;
            }
            if (!hash) {
                if(nums.empty()) return false;
                nums.push(0);
            }
            if (hash) {
                if(nums.empty()) return false;
                nums.top() += 1;

                while(!nums.empty() and nums.top()==2){
                    nums.pop(); 
                    if(!nums.empty()) nums.top() += 1;
                }
            }
        }
        
        if(nums.empty()) return true;
        return false; 
    }
};