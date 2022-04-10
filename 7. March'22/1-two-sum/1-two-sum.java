class Solution {
    public int[] twoSum(int[] nums, int target) {
        int res[] = new int[2]; 
        HashMap<Integer, Integer> temp = new HashMap<>(); 
        
        int size = nums.length;
        for(int i = 0; i < size; i++) {
            int diff = target - nums[i]; 
            if(temp.containsKey(diff)) {
                res[0] = i; 
                int ind = temp.get(diff);
                res[1] = ind; 
                return res; 
            }
            
            temp.put(nums[i], i);
        }
        
        return res; 
    }
}