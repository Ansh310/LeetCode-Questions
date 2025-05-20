class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int n = nums.size();
        int maxConsecutiveOnes = 0; int temp = k; int st = 0, end = 0;

        while(end < n) {
            while(end < n && (temp > 0 || nums[end] == 1)) {
                if(nums[end] == 0) temp--;
                end++;
            }

            maxConsecutiveOnes = max(maxConsecutiveOnes, end - st);

            while(st < n && nums[st] == 1) st++;
            st++;
            temp++;
        }

        return maxConsecutiveOnes;
    }
};