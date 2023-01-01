class Solution {
    
    int[] spf = new int[(int)1e4+1];
    
    public void primeSieve(){
        int MAXN = (int)1e4+1; 
        spf[1] = 1;
        for(int i = 2; i < MAXN; i++)
            spf[i] = i;
        
        for(int i = 4; i < MAXN; i+=2)
            spf[i] = 2;
        
        for(int i = 3; i < MAXN; i++){
            if(spf[i] == i){
                for(int j = i*i; j < MAXN; j+=i){
                    if(spf[j] == j)
                        spf[j] = i;
                }
            }
        }
        return;
    }
    
    
    public int distinctPrimeFactors(int[] nums) {
        primeSieve(); 
        HashSet<Integer> unique = new HashSet<>();
        
        for(int i : nums){
            while(i != 1){
                unique.add(spf[i]);
                i /= spf[i];
            }
        }
        
        return unique.size();
        
    }
}