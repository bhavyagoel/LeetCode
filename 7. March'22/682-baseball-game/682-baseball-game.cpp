class Solution {
public:
    int calPoints(vector<string>& ops) {
        
        stack<int> temp; 
        
        for(auto it : ops) {
            
            if(it == "C") {
                temp.pop(); 
            }
            else if(it == "D") {
                int tmp = temp.top(); 
                temp.push(tmp*2);
            }
            else if(it == "+"){
                int a = temp.top(); 
                temp.pop(); 
                int b = temp.top(); 
                temp.push(a); 
                temp.push(a+b);
            }
            else{
                temp.push(stoi(it));
            }
        }
        
        int res = 0; 
        while(!temp.empty()){
            res += temp.top(); 
            temp.pop(); 
        }
        
        return res;
    }
};