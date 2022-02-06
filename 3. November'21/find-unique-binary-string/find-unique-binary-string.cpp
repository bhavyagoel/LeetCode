// https://leetcode.com/problems/find-unique-binary-string/discuss/1418687/Detailed-Explanation-O(N)-Java-C%2B%2B-Python-short-concise-code-Cantor's-Diagonalization

// https://en.wikipedia.org/wiki/Cantor%27s_diagonal_argument

// Cantor's Diagonalization

class Solution {
public:
    string findDifferentBinaryString(vector<string>& nums) {
        
        string res; 
        for (int i = 0 ; i < nums.size(); i++) {
            res += nums[i][i]=='0'?'1':'0';
        }
        return res; 
    }
};

/*
class Solution {
public:
    unordered_map<string, int> vals;
    string ans; 
    
    string findDifferentBinaryString(vector<string>& nums) {
        string num = "10";
        string temp;
        int len = nums[0].length(); 
        
        for(auto num : nums) {
            vals[num]++;
        }
        helper(num, temp, 0, len);
        return ans;
    }
    
    void helper(string& nums, string& temp, int index, int len) {
        
        if(temp.length() == len and !vals[temp]) {
            ans = temp; 
            return; 
        }
        
        for(int i = index; i < len; i++) {
            for(int j = 0; j < 2; j++) {
                temp.push_back(nums[j]);
                helper(nums, temp, i+1, len);
                temp.pop_back(); 
            }
        }        
    }
};
*/