class Solution {
public:
    int firstUniqChar(string s) {
        unordered_map<char, pair<int, int>> temp; 
        for(int i = 0 ; i < s.length(); i++){
            if (temp.find(s[i]) == temp.end()){
                temp[s[i]] = make_pair(1, i);
            }else{
                temp[s[i]] = make_pair(temp[s[i]].first+1, i);
            }
        }
        
        for(auto i : s){
            if(temp[i].first == 1){
                return temp[i].second;
            }
        }
        return -1;
    }
};