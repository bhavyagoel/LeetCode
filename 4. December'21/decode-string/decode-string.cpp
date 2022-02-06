class Solution {
public:
    string decodeString(string s) {
        
        stack<char> alpha; 
        int len = s.length(); 
        
        for(int i = len-1; i > -1; i--) {
            if (s[i] == ']' or isalpha(s[i])) {
                alpha.push(s[i]);
            }
            
            
            if(s[i]=='['){
                string insideBracks;
                while(alpha.top() != ']') {
                    insideBracks.push_back(alpha.top());
                    alpha.pop(); 
                }
                alpha.pop(); 
                cout<<insideBracks<<endl;
                i-=1; // To manage '[' bracket
                
                int multiple = 1;
                int count = 0; 
                
                while(i>=0){
                    if(!isdigit(s[i])) break;
                    int digit = s[i]-'0';
                    count += digit*multiple;
                    multiple *= 10;
                    i--;
                }
                i+=1; //To handle the previous bracket.
                
                string toPushInStasck; 
                while(count--) {
                    toPushInStasck += insideBracks;
                }
                cout<<toPushInStasck<<endl;
                
                reverse(toPushInStasck.begin(), toPushInStasck.end());
                for(auto w : toPushInStasck) {
                    alpha.push(w);
                }
            }
        }
        
        string res; 
        while(!alpha.empty()) {
            res += alpha.top(); 
            alpha.pop();
        }
        
        return res;
    }
};