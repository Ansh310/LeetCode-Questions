class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<int>> dp(m, vector<int>(n, 0));

        dp[m - 1][n - 1] = grid[m - 1][n - 1];

        for(int i = m - 2; i >= 0; i--) dp[i][n - 1] = dp[i + 1][n - 1] + grid[i][n - 1];

        for(int j = n - 2; j >= 0; j--) dp[m - 1][j] = dp[m - 1][j + 1] + grid[m - 1][j];

        for(int i = m - 2; i >= 0; i--) {
            for(int j = n - 2; j >= 0; j--) {
                dp[i][j] = min(dp[i + 1][j], dp[i][j + 1]) + grid[i][j];
            }
        }
        return dp[0][0];
    }
};