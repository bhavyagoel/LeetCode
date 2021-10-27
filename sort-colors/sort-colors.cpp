class Solution {
public:
    void sortColors(vector<int>& nums) {
        /*
        int a = 0, b = 0, c = 0; 
        for(int i = 0 ; i < nums.size();i++) {
            a = nums[i]==0?a+1:a;
            b = nums[i]==1?b+1:b;
            c = nums[i]==2?c+1:c;
        }
        
        for(int i = 0 ; i < a; i++) {
            nums[i] = 0;
        }
        for(int i = a; i<a+b; i++){
            nums[i] = 1;
        }
        for(int i = a+b; i<a+b+c;i++){
            nums[i] = 2;
        }
        */
        
        int n = nums.size();
        int second=n-1, zero=0;
        for (int i=0; i<=second; i++) {
            while (nums[i]==2 && i<second) swap(nums[i], nums[second--]);
            while (nums[i]==0 && i>zero) swap(nums[i], nums[zero++]);
        }
    }

};