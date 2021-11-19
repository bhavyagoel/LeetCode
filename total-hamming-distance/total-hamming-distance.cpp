// https://leetcode.com/problems/total-hamming-distance/discuss/96226/Java-O(n)-time-O(1)-Space


class Solution {
public:
    int totalHammingDistance(vector<int>& nums) {
        int res = 0;
        for(int i = 0 ; i < 32; i++) {
            int mask = 1<<i; 
            int ones = 0; 
            int zeros = 0; 
            for(int j = 0 ; j < size(nums); j++) {
                if(mask&nums[j]) ones++; 
                else zeros++;
            }
            
            res += ones*zeros;
        }
        
        return res;
    }
};

/*
class Solution {
public:
    int totalHammingDistance(vector<int>& nums) {
        """
        int res = 0; 
        for(int i = 0; i < nums.size(); i++) {
            for(int j = i+1; j < nums.size(); j++) {
                res += __builtin_popcount(nums[i]^nums[j]);
            }
        }
        """
        helper(nums, 0, 0, 0);
        return res; 
    }
    int res = 0; 
    void helper(vector<int> &nums, int index, int num, int cnt) {
        
        if(cnt==2) {
            res += __builtin_popcount(num);
            return;
        }
        
        for(int i = index; i < nums.size(); i++) {
            if(cnt<2) helper(nums, i+1, num^nums[i], cnt+1);
            else return;
        }
    }
};

*/ 