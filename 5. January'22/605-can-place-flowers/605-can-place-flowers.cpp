class Solution {
public:
    bool canPlaceFlowers(vector<int>& f, int n) {
        if(f.size()==1 and n == 1 and f[0] == 0) return true;        
        int numOnes = 0; 
        int numZeros = 0; 
        
        int cnt = 0; 
        int strt = 0; 
        while(strt<f.size() and f[strt]!=1) {
            numZeros++;
            strt++;
        }
        cnt += numZeros>0?numZeros/2:numZeros;
        
        if(strt==f.size()) {
            return (numZeros+1)/2>=n;
        }
        numZeros = 0;
        
        int end = f.size()-1;
        while(end>=0 and f[end]!=1) {
            numZeros++;
            end--;
        }
        cnt += numZeros>0?numZeros/2:numZeros;
        numZeros = 0;
        
        for(int i = strt; i <= end; i++) {
            if(f[i]==0) {
                numZeros++;
            }
            if(f[i]==1) {
                numOnes++;
            }
            
            if(numOnes==2) {
                cnt += numZeros>0?(numZeros-1)/2:numZeros;
                numOnes = 1;
                numZeros = 0;
            }
        }
        cout<<cnt<<endl;
        return cnt >= n;
    }
};