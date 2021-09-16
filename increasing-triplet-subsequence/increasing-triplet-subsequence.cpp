class Solution {
public:  
    // increasingTriplet_forK
    bool increasingTriplet(vector<int>& nums) {
        
        int n = nums.size();
        
        // Kth order sequence
        int k =3;
        vector<int> maxTill_j(k-1);
        
        for(auto &i : maxTill_j) {
            i = INT_MAX;
        }
        
        for(auto i : nums) {
            int count = 0;
            for(auto &j : maxTill_j) {
                
                if (j >= i) {
                    j = i;
                    break;
                }
                
                else if (count == k-2) {
                    return true;
                }
                count++;
                
            }
        }
        
        return false;
        
        
    }
    
    
//     bool increasingTriplet(vector<int>& nums) {
        
//         int first = INT_MAX; 
//         int second = INT_MAX; 
        
//         for(auto i : nums) {
//             if (first > i) {
//                 first = i;
//             }
//             else if(second > i) {
//                 second = i;
//             }
//             else {
//                 return true; 
//             }
//         }
        
//         return false; 
//     }
};