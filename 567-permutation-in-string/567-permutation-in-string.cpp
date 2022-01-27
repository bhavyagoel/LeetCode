class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        
        vector<int> first(26,0);
        for(auto it : s1) {
            first[it-'a'] += 1;
        }
        
        int i = 0; 
        int j = 0; 
        int n = s2.length(); 
        while(i<n or j<n) {
            if(!first[s2[j]-'a']){
                j+=1;
                i=j;
            }else{
                vector<int> temp(26,0); 
                while(j<n and first[s2[j]-'a']!=0) {
                    if(first[s2[j]-'a']==temp[s2[j]-'a']) {
                        temp[s2[i]-'a'] -= 1;
                        i+=1;
                        continue;
                    }
                    temp[s2[j]-'a'] += 1;
                    j+=1;
                    if(temp==first) return true;
                }                
                i=j;
            }
        }
        
        return false; 
    }
};