class Solution {
public:
    bool asteroidsDestroyed(__int128 mass, vector<int>& a) {
        
        sort(a.begin(), a.end());
        int n = a.size(); 
        for(int i = 0; i < n; i++) {
            if(mass<a[i]) {
                return false;
            }else{
                mass += a[i];
            }
        }
        return true;
    }
};