class Solution {
public:
    int nextGreaterElement(int n) {
        string temp = to_string(n);
        int len = temp.length(); 
        if(len==1) return -1;
        
        
        int i = len-2;
        
        while(i>=0 and temp[i+1]<=temp[i]) i--;
        if(i<0) return -1;
        
        if(i>=0){
            int j = len-1; 
            while(temp[j]<=temp[i]) j--;
            swap(temp[j], temp[i]);
        }
        
        i += 1;
        int j = len-1; 
        while(i<=j) {
            swap(temp[i], temp[j]);
            i++;
            j--;
        }
        
        long long int ans = 0; 
        long long int mult = 1; 
        while(!temp.empty()) {
            ans += (temp.back()-'0')*mult; 
            temp.pop_back();
            mult *= 10;
        }
        
        return ans>INT_MAX?-1:ans;
    }
};