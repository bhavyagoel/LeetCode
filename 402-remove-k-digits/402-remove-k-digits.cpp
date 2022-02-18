class Solution {
public:
    string removeKdigits(string num, int k) {
        
        int n = num.length(); 
        stack<char> temp; 
        int i = 0; 
        while(i<n) {
            
            if(temp.empty()) temp.push(num[i]);
            else{
                while(k and !temp.empty() and temp.top()>num[i]){
                    k--; 
                    temp.pop(); 
                }
                temp.push(num[i]);
            }
            
            if(temp.size()==1 and temp.top()=='0') temp.pop();
            i+=1; 
        }
        
        
        while(k and !temp.empty()){
            k -= 1; 
            temp.pop();
        }
        
        string res; 
        while(!temp.empty()){
            res.push_back(temp.top()); 
            temp.pop(); 
        }
        reverse(res.begin(), res.end()); 
        return res.size()?res:"0"; 
    }
};