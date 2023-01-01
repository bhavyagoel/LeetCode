class Solution {
    public List<Integer> selfDividingNumbers(int left, int right) {
        List<Integer> ans = new ArrayList<>(); 
        
        for(int i = left; i <= right; i++){
            int temp = i; 
            boolean flag = true; 
            while(temp != 0){
                int dig = temp % 10; 
                if(dig == 0 || i % dig != 0){
                    flag = false;
                    break;
                }
                temp = temp / 10; 
            }
            
            if(flag)
                ans.add(i);
        }
        
        return ans;
    }
}