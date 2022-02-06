class Solution {
public:
    bool placeWordInCrossword(vector<vector<char>>& board, string word) {
        return helper(board, word);
    }
    
private:
    bool helper(vector<vector<char>> &board, string &word) {
        
        vector<vector<char>>alpha; 
        
        // Left to Right
        for(int i = 0; i < board.size(); i++) {
            for(int j = 0 ; j < board[0].size(); j++) {
                vector<char> temp;
                while(j<board[0].size() && board[i][j] != '#'){
                    temp.push_back(board[i][j]);
                    j++;
                }
            if(temp.size() != 0) alpha.push_back(temp);
            }
        }
        
        // Right to Left
        for(int i = 0; i<board.size(); i++) {
            for(int j = board[0].size()-1; j>-1; j--) {
                vector<char> temp;
                while(j>-1 && board[i][j] != '#'){
                    temp.push_back(board[i][j]);
                    j--;
                }
                if(temp.size() != 0) alpha.push_back(temp);
            }
        }
        
        // Up to Down
        for(int i = 0; i < board[0].size(); i++) {
            for(int j = 0 ; j < board.size(); j++) {
                vector<char> temp;
                while(j<board.size() && board[j][i] != '#'){
                    temp.push_back(board[j][i]);
                    j++;
                }
            if(temp.size() != 0) alpha.push_back(temp);
            }
        }
        
        // Down to Up
        for(int i = board[0].size()-1; i > -1; i--) {
            for(int j = board.size()-1 ; j >-1; j--) {
                vector<char> temp;
                while(j>-1 && board[j][i] != '#'){
                    temp.push_back(board[j][i]);
                    j--;
                }
            if(temp.size() != 0) alpha.push_back(temp);
            }
        }
        
        for(int i = 0 ; i < alpha.size(); i++) {
            bool flag = false;
            if (alpha[i].size() != word.length());
            else {
                int j = 0; 
                while(j < alpha[i].size()) {
                    if(alpha[i][j] == word[j] || alpha[i][j] == ' ') {
                        flag = true;
                        j++;
                    }
                    else {
                        flag = false; 
                        break;
                    }
                }
                if(flag) return true; 
            }
        }

        return false; 
    }
};