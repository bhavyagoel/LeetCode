class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        vector<vector<string>> words; 
        unordered_map<string, vector<int>> missPosIndex;
        
        bool checkExist = false; 
        for(auto &it : wordList) {
            if(it == endWord) checkExist = true; 
        }
        
        if(!checkExist) return 0;
        
        int n = wordList.size();
        
        for(int i = 0; i < n; i++) {
            int len = wordList[i].size(); 
            vector<string> temp; 
            string tmp = wordList[i];
            for(int j = 0; j < len; j++) {
                tmp[j] = '$';
                missPosIndex[tmp].push_back(i);
                temp.push_back(tmp);
                tmp = wordList[i];
            }
            words.push_back(temp);
        }
        
        
        vector<bool> visited(n,false);
        queue<int> bfs;
        string temp = beginWord;
        
        int lvl = 1; 
        for(int i = 0; i < beginWord.size(); i++) {
            temp[i] = '$';
            for(auto &ind : missPosIndex[temp]) {
                if(wordList[ind]==endWord) return lvl+1;
                if(!visited[ind]) {
                    visited[ind] = true;
                    bfs.push(ind);
                }
            }
            temp = beginWord;
        }
                
        while(!bfs.empty()) {
            int curr = bfs.size(); 
            lvl += 1;
            while(curr--) {
                int front = bfs.front(); 
                bfs.pop(); 
                
                for(auto &it : words[front]) {
                    for(auto &temp : missPosIndex[it]) {
                        if(wordList[temp]==endWord) return lvl+1;
                        if(!visited[temp]) {
                            visited[temp] = true;
                            bfs.push(temp);
                        }
                    }
                }
                
            }
        }
        
        return 0;
    }
};