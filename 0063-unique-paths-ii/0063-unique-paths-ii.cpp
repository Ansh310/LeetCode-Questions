class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();

        vector<vector<long long int>> dp(m, vector<long long int>(n, 0));

        dp[m - 1][n - 1] = obstacleGrid[m - 1][n - 1] ? 0 : 1;

        for(int j = n - 2; j >= 0; j--) {
            if(obstacleGrid[m - 1][j] == 1) dp[m - 1][j] = 0;
            else dp[m - 1][j] = dp[m - 1][j + 1];
        }

        for(int i = m - 2; i >= 0; i--) {
            if(obstacleGrid[i][n - 1] == 1) dp[i][n - 1] = 0;
            else dp[i][n - 1] = dp[i + 1][n - 1];
        }

        for(int i = m - 2; i >= 0; i--) {
            for(int j = n - 2; j >= 0; j--) {
                if(obstacleGrid[i][j] == 1) dp[i][j] = 0;

                else dp[i][j] = dp[i + 1][j] + dp[i][j + 1];
            }
        }
        return dp[0][0];
    }
};