class Solution {
public:
    int orderOfLargestPlusSign(int n, vector<vector<int>>& mines) {
        int left[n][n];
        int right[n][n];
        int up[n][n];
        int down[n][n];
        
        int arr[n][n];
        fill(&arr[0][0], &arr[0][0] + sizeof(arr)/sizeof(arr[0][0]) , 1);
        // memset( &arr[0][0], 1, sizeof(arr) );
        memset( &left[0][0], 0, sizeof(left) );
        memset( &right[0][0], 0, sizeof(right) );
        memset( &up[0][0], 0, sizeof(up) );
        memset( &down[0][0], 0, sizeof(down) );
        
        for(auto i : mines) {
            arr[i[0]][i[1]] = 0;
        }
        
        
        for(int i = 0 ; i < n ; i++) {
            int sum = 0;
            for(int j = 0 ; j < n; j++) {
                sum += arr[i][j];
                if(arr[i][j] == 1) {
                    left[i][j] = sum;
                }
                else {
                    sum = 0;
                }
            }
        }
        
        for(int i = n-1 ; i >-1 ; i--) {
            int sum = 0;
            for(int j = n-1 ; j >-1; j--) {
                sum += arr[i][j];
                if(arr[i][j] == 1) {
                    right[i][j] = sum;
                }
                else {
                    sum = 0;
                }
            }
        }
        
        
        for(int i = n-1 ; i >-1 ; i--) {
            int sum = 0;
            for(int j = n-1 ; j >-1; j--) {
                sum += arr[j][i];
                if(arr[j][i] == 1) {
                    down[j][i] = sum;
                }
                else {
                    sum = 0;
                }
            }
        }
        
        for(int i = 0 ; i < n ; i++) {
            int sum = 0;
            for(int j = 0 ; j < n; j++) {
                sum += arr[j][i];
                if(arr[j][i] == 1) {
                    up[j][i] = sum;
                }
                else {
                    sum = 0;
                }
            }
        }
        
        
        int max = INT_MIN;
        for(int i = 0 ; i < n; i++) {
            for(int j = 0 ; j < n ; j++) {
                int val = min(left[i][j],min(right[i][j],min(up[i][j],down[i][j])));
                if ((left[i][j]>=val) && (right[i][j] >= val) && (up[i][j] >= val) && (down[i][j] >= val)) {
                    if(max < val) {
                        max = val;
                }
            }
        }
        }
        
        return max;
    }
};