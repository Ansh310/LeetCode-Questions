class Solution {
public:
    vector<int> getSneakyNumbers(vector<int>& nums) {
        int n = nums.size();
        int i = 0;

        while(i < n) {
            if(nums[i] == i) {
                i++;
                continue;
            }

            int j = nums[i];
            if(j == nums[j]) {
                i++;
                continue;
            }

            nums[i] = nums[j];
            nums[j] = j;
        }

        return {nums[n - 1], nums[n - 2]};
    }
};