class Solution {
public:
    int findComplement(int num) {
        int ans =0;
        int i=0;
        while(num){
            int rev_lsb = !(num &1);
            rev_lsb = rev_lsb << i;
            ans = ans | rev_lsb;
            num = num>>1;
            i++;
        }
        return ans;
    }
};