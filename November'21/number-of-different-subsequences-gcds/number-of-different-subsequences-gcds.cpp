 // If a is the factor of array [x,y,z], but gcd(x,y,z) is greater than a, then a is never going to be gcd of any subsequence of that array

class Solution {
public:
    int gcd(int a, int b) {
        if(a==0){
            return b; 
        }
        return gcd(b%a, a);
    }
    
    int countDifferentSubsequenceGCDs(vector<int>& nums) {
        int factors[200001];
        memset(factors, 0, sizeof(factors));
        
        for(int i = 0 ; i < size(nums); i++) {
            for(int j = 1; j*j<=nums[i]; j++) {
                if (nums[i]%j == 0) {
                    int fac1 = j; 
                    int fac2 = nums[i]/j;
                    
                    factors[fac1] = gcd(nums[i], factors[fac1]);
                    factors[fac2] = gcd(nums[i], factors[fac2]);
                }
            }
        }
        
        int res = 0;
        for(int i = 1 ; i < 200001; i++) {
            if(factors[i] == i) res++;
        }
        
        return res; 
    }
};

/*
class Solution {
public:
    unordered_set<int> res; 
    map<vector<int>, int> divisors; 
    
    int gcd(int a, int b) {
        if(a==0){
            return b; 
        }
        return gcd(b%a, a);
    }
    
    int countDifferentSubsequenceGCDs(vector<int>& nums) {
        vector<int> temp; 
        helper(nums, temp, 0, 1);
        return res.size(); 
    }
    
    void helper(vector<int>& nums, vector<int>&temp, int index, int val) {
        
        for(int i = index; i<nums.size(); i++) {
            temp.push_back(nums[i]);
            if(temp.size()<2){
                divisors[temp] = nums[i];
                helper(nums, temp, i+1, nums[i]);
                res.insert(nums[i]);
            }else{
                if(!divisors[temp]) divisors[temp] = gcd(val, nums[i]);
                helper(nums, temp, i+1, divisors[temp]);
                res.insert(divisors[temp]); 
            }
            temp.pop_back();
            
        }
    }
};
*/