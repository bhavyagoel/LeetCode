class Solution {
public:
    unordered_map<int, vector<int>> child;
    int res = 0; 
    long long maxScore = INT_MIN;
    
    int countHighestScoreNodes(vector<int>& p) {
        
        for(int i = 0; i < p.size(); i++) {
            if(p[i]!=-1) child[p[i]].push_back(i);
        }
        countSubtree(p, 0);
        return res;
    }
    
    
    int countSubtree(vector<int>& p, int curr) {
        
        long long sum = 1, prod = 1; 
        for(int i = 0; i < child[curr].size(); i++) {
            int cnt = countSubtree(p, child[curr][i]);      
            prod *= cnt; 
            sum += cnt; 
        }
        long long currScore = prod*(max(1ll, (long long)p.size() - sum));
        if(maxScore < currScore) {
            maxScore = currScore;
            res = 1;
        }
        else if(maxScore == currScore) res += 1;
        return sum; 
    }
    /*
    unordered_map<int, int> score; 
    int countHighestScoreNodes(vector<int>& p) {
        
        for(int i = 0; i < p.size(); i++) {
            if(p[i]!=-1) child[p[i]].push_back(i);
        }
        countSubtree(0);
        
        
        long long maxScore = INT_MIN;
        int res = 0; 
        for(int i = 0; i < p.size(); i++){
            long long currScore = score[0] - score[i];
            currScore = currScore?currScore:1;
            for(int j = 0; j < child[i].size(); j++) {
                currScore *= score[child[i][j]];
            }
            
            if(maxScore < currScore) {
                maxScore = currScore;
                res = 1;
            }
            else if(maxScore == currScore) res += 1;
        }
        
        return res;
    }
    
    int countSubtree(int curr) {
        
        int sum = 1; 
        for(int i = 0; i < child[curr].size(); i++) {
            sum += countSubtree(child[curr][i]);            
        }
        
        score[curr] = sum;
        return sum; 
    }
    */
    
};