class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
       int m = matrix.size(), n = matrix[0].size();

       vector<vector<int>> dp(m, vector<int>(n, 0));

       for(int j = 0; j < n; j++) dp[m - 1][j] = matrix[m - 1][j];

       for(int i = m - 2; i >= 0; i--) {
         for(int j = 0; j < n; j++) {
            int val = INT_MAX;

            val = min(val, dp[i + 1][j]);

            if(j - 1 >= 0) val = min(val, dp[i + 1][j - 1]);

            if(j + 1 < n) val = min(val, dp[i + 1][j + 1]);

            dp[i][j] = val + matrix[i][j];
         }
       }
       int ans = INT_MAX;
       for(int j = 0; j < n; j++) {
        ans = min(ans, dp[0][j]);
       }
       return ans;
    }
};