class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int lastUsedIdx = 1, i = 1;
            int countPrev = 1;
            while (i < nums.size()) {
                if (nums[i] != nums[i-1]) {
                    countPrev = 1;
                    nums[lastUsedIdx++] = nums[i];
                }
                else {
                    if (countPrev < 2) {
                        nums[lastUsedIdx++] = nums[i];
                        countPrev++;
                    }
                }
                i++;
            }
        return lastUsedIdx;
    }
};