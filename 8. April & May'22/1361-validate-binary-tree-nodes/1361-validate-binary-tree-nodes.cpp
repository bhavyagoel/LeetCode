class Solution {
public:
    bool validateBinaryTreeNodes(int n, vector<int>& leftChild, vector<int>& rightChild) {
        vector<int> parent(n, -1);
        vector<int> checkNc(n, 0);
        
        for(int i = 0; i < n; i++) {
            if(leftChild[i] != -1) {
                if(parent[leftChild[i]] != -1) return false;
                parent[leftChild[i]] = i;
            }
            
            if(rightChild[i] != -1) {
                if(parent[rightChild[i]] != -1) return false; 
                parent[rightChild[i]] = i;
            }
            checkNc[i] = 1;
        }
        
        bool p = false; 
        for(int i = 0; i < n; i++) {
            if(!checkNc[i]) return false; 
            
            if(parent[i] == -1) {
                if(!p) p = true; 
                else return false; 
            }
            
            int temp = i;
            while(parent[temp] != -1){
                if(i == parent[temp]) return false; 
                temp = parent[temp];
            }
        }
        
        return p and true;
    } 
};