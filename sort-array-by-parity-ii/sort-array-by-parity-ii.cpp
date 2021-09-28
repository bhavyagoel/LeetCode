class Solution {
public:
    vector<int> sortArrayByParityII(vector<int>& nums) {
        return helper(nums);
    }
    
private:
    vector<int> helper(vector<int> &nums) {
        int evenInd = 0; 
        int oddInd = 1; 
        
        for(int i = 0 ; i < nums.size(); i++) {
            if(i%2 == 0 && nums[i]%2!=0) {
                swap(nums[i], nums[oddInd]);
                oddInd +=2;
                i--;
            }
            else if(i%2 != 0 && nums[i]%2==0) {
                swap(nums[i], nums[evenInd]);
                evenInd +=2;
                i--;
            }
        }
        
        return nums;
    }
};