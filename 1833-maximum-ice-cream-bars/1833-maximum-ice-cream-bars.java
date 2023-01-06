class Solution {
    public int maxIceCream(int[] costs, int coins) {
        Arrays.sort(costs);
        int res = 0;
        for(int cost : costs){
            if(coins>=cost){
                coins -= cost;
                res++;
            }else
                break;
        }
        
        return res;
    }
}