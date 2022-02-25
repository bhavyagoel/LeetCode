class Solution {
public:
    vector<long long int>tokeinizingFunction(string line){
         // Vector of string to save tokens
    vector <long long int> tokens;

    // stringstream class check1
    stringstream check1(line);

    string intermediate;

    // Tokenizing w.r.t. space '.'
    while(getline(check1, intermediate, '.'))
    {
        tokens.push_back(stoi(intermediate));
    }
     return tokens;
    }
    int compareVersion(string s1, string s2) {
         vector<long long int>v1 = tokeinizingFunction(s1);
         vector<long long int>v2 = tokeinizingFunction(s2);
        int i=0;
        int j=0;
        // for(auto &it : v1){
        //     cout<<it<<"   ";
        // }
        for(int i=0 ; i < max(v1.size() , v2.size()) ; i++){
            if(((i>=v1.size()) ? 0 : v1[i])>(i>=v2.size() ? 0 :v2[i]))return 1;
            else if(((i>=v1.size()) ? 0 : v1[i])<(i>=v2.size() ? 0 :v2[i]))return -1;
        }
    return 0;
    }
}; 