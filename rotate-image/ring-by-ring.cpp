class Solution {
public:
/*
    Input 
    1, 2, 3
    4, 5, 6
    7, 8, 9 


    for-loop 1 
    swap1               swap2               swap3
    1<->3               3<->9              9<->7

    3, 2, 1            9, 2, 1            7, 2, 1
    4, 5, 6    =>      4, 5, 6    =>      4, 5, 6
    7, 8, 9            7, 8, 3            9, 8, 3

    

    for-loop 2 
    swap1              swap2              swap3
    2<->6              6<->8              8<->4

    7, 6, 1            7, 8, 1            7, 4, 1
    4, 5, 2    =>      4, 5, 2    =>      8, 5, 2
    9, 8, 3            9, 6, 3            9, 6, 3
    

    output     
    7, 4, 1,
    8, 5, 2,
    9, 6, 3,
*/
    // Rotating ring by ring
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int a = 0;
        int b = n-1;
        while(a<b){
            for(int i=0;i<(b-a);++i){
                swap(matrix[a][a+i], matrix[a+i][b]);
                swap(matrix[a][a+i], matrix[b][b-i]);
                swap(matrix[a][a+i], matrix[b-i][a]);
            }
            ++a;
            --b;
        }
    }
//     void rotate(vector<vector<int>>& matrix) {
        
//         int n = matrix.size(); 
        
//         // Take transpose of the matrix
//         for(int i = 0 ; i < n ; i++) {
//             for(int j = 0 ; j <=i ;j++) {
//                 swap(matrix[i][j], matrix[j][i]);
//             }
//         }
        
//         // Reverse each row of the matrix
//         for(int i = 0 ; i < n; i++) {
//             reverse(matrix[i].begin(), matrix[i].end());
//         }
//     }
};
