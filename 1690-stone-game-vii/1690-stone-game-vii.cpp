class Solution {
public:
    vector<int> prefixSum;
    int getSum(int left, int right) {
            return prefixSum[right + 1] - prefixSum[left];
    }
    int stoneGameVII(vector<int>& stones) {
        int n = stones.size();
        prefixSum.assign(n + 1, 0);
        for(int i = 0; i < n; i++) {
            prefixSum[i + 1] = prefixSum[i] + stones[i];
        }

        vector<vector<int>> dp(n, vector<int>(n, 0));

        for(int i = n - 1; i >= 0; i--) {
            for(int j = i + 1; j < n; j++) {
                int leftMost = getSum(i + 1, j);
                int rightMost = getSum(i, j - 1);

                dp[i][j] = max(leftMost - dp[i + 1][j], rightMost - dp[i][j - 1]);
            }
        }
        return dp[0][n - 1];
    }
};