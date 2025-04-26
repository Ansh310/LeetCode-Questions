class Solution {
public:
    int maxRob(vector<int>& nums, int st, int end, int n) {
        if(n == 1) return nums[st];
        vector<int> dp(n, 0);

        dp[0] = nums[st]; dp[1] = max(nums[st], nums[st + 1]);

        for(int i = st + 2, j = 2; i <= end; i++, j++) {
            dp[j] = max(dp[j - 1], dp[j - 2] + nums[i]);
        }
        return dp[n - 1];
    }

    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n == 1) return nums[0];
        int val1 = maxRob(nums, 0, n - 2, n - 1);
        int val2 = maxRob(nums, 1, n - 1, n - 1);
        return max(val1, val2);
    }
};