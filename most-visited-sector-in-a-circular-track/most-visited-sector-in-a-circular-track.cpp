class Solution {
public:
    vector<int> mostVisited(int n, vector<int>& rounds) {
        return helper(n, rounds);
    }
    
private:
    vector<int> helper(int &n, vector<int>& rounds) {
        
        vector<int>temp(n, 0);
        vector<int> res; 
        int max_possible = INT_MIN;
        for(int i = 1; i < rounds.size(); i++) {
            if(rounds[i] > rounds[i-1]) {
                for(int j = rounds[i-1]; j < rounds[i]; j++) {
                    temp[j-1]++;
                    max_possible = max(temp[j-1], max_possible);
                }
            }
            else {
                for(int j = rounds[i-1]; j <= n; j++) {
                    temp[j-1]++;
                    max_possible = max(temp[j-1], max_possible);
                }
                for(int j = 1; j < rounds[i]; j++) {
                    temp[j-1]++;
                    max_possible = max(temp[j-1], max_possible);
                }
            }
        }
        temp[rounds[rounds.size()-1]-1]++;
        max_possible = max(temp[rounds[rounds.size()-1]-1], max_possible);
        
        for(int i = 0 ; i < n; i++) {
            if(temp[i] == max_possible) {
                res.push_back(i+1);
            }
        }
        return res; 
        
    }
};