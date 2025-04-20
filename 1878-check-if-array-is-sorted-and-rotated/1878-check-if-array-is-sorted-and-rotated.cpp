class Solution {
public:
    bool check(vector<int>& nums) {
        int n = nums.size(), inversionCount = 0;

        for(int i = 1; i < n; i++) {
            if(nums[i] < nums[i - 1]) {
                inversionCount += 1;
            }
        }
        if(nums[n - 1] > nums[0]) inversionCount++;

        return inversionCount <= 1;
    }
};