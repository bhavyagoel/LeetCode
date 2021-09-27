class Solution {
public:
    int numUniqueEmails(vector<string>& emails) {
        return helper(emails);
    }
    
private:
    int helper(vector<string> & emails) {
        set<string> res;
        
        for(auto &email : emails) {
            int i = 0;
            string temp = "";
            bool flagCopy = true;
            while(email[i] != '@' && i<email.length()) {
                if(email[i] == '+') {
                    flagCopy = false;
                }
                if(email[i] != '.' && flagCopy) {
                    temp+=email[i];
                }
                i++;
            }
            
            while(i<email.length()) {
                temp+= email[i];
                i++;
            }
            // email = temp;
            res.insert(temp);
        }
        
        
        // for(auto &email : emails) {
        //     cout<<email<<endl;
        // }
        
        return res.size();
    }
};