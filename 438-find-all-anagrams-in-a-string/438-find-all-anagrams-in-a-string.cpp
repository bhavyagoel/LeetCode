class Solution {
public:
    vector<int> findAnagrams(string s2, string s1) {
        vector<int> first(26,0);
        vector<int> res; 
        for(auto it : s1) {
            first[it-'a'] += 1;
        }
        
        int i = 0; 
        int j = 0; 
        int n = s2.length(); 
        while(i<n or j<n) {
            if(!first[s2[j]-'a']){
                j+=1;
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
                    if(temp==first) {
                        res.push_back(i);
                    }
                    
                }                
            }
            i=j;
        }
        
        return res; 
    }
};

