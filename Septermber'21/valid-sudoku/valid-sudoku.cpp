class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        return check_rows(board) && check_cols(board) && check_3x3(board);
    }
    
private:
    bool check_rows(vector<vector<char>>& board) {
        for(int i = 0 ; i < 9; i++)  {
            map<char, int> temp;
            for(int j = 0; j < 9; j++) {
                if(temp[board[i][j]] && board[i][j] != '.') {
                    return false;
                }
                temp[board[i][j]] = 1;
            }
        }
        return true; 
    }
    
    bool check_cols(vector<vector<char>>& board) {
        
        for(int i = 0 ; i < 9; i++)  {
            map<char, int> temp;
            for(int j = 0; j < 9; j++) {
                if(temp[board[j][i]] && board[j][i] != '.') {
                    return false;
                }
                temp[board[j][i]] = 1;
            }
        }
        return true; 
    }
    
    bool check_3x3(vector<vector<char>>& board) {
        
        vector<vector<int>>temp = {{0,0}, {3,3}, {0,3}, {3,6}, {0,6}, {3,9},
                                   {3,0}, {6,3}, {3,3}, {6,6}, {3,6}, {6,9}, 
                                   {6,0}, {9,3}, {6,3}, {9,6}, {6,6}, {9,9}};

        int k = 9; 
        int tmp = 0;
        
        while(k--) {
            map<char, int> alpha;
            
            for(int i = temp[tmp][0]; i<temp[tmp+1][0]; i++) {
                for(int j = temp[tmp][1]; j < temp[tmp+1][1]; j++) {
                    if(alpha[board[i][j]] && board[i][j] != '.') {
                        return false;
                    }
                    alpha[board[i][j]] = 1;
                }
            }
            tmp+=2;
        }
        return true;
    }
    
};