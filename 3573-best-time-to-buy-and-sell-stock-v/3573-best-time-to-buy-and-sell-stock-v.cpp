class Solution {
public:
    long long maximumProfit(vector<int>& prices, int k) {
        int n = prices.size();

        vector<vector<vector<long long>>> dp(n, vector<vector<long long>>(k + 1, vector<long long>(3, 0)));

         // Base case 1: Day 0 (no transactions yet)
        for (int j = 1; j <= k; j++) {
            dp[0][j][0] = 0;   // No stock, no profit on the first day
            dp[0][j][1] = -prices[0];  // Buying stock on day 0 results in negative profit
            dp[0][j][2] = prices[0];   // No short-selling profit on day 0
        }


        for(int i = 1; i < n; i++) {
            for(int j = 1; j <= k; j++) {
                for(int l = 0; l <= 2; l++) {
                    if(l == 0) {
                        dp[i][j][l] = max({
    dp[i - 1][j][l],                    // Do nothing
    prices[i] + dp[i - 1][j][1],  // Buy (enter LONG)
    -prices[i] + dp[i - 1][j][2]    // Sell (enter SHORT)
});


                    }
                    else if(l == 1) {
                        dp[i][j][l] = max(dp[i - 1][j][l], -prices[i] + dp[i - 1][j - 1][0]);
                    }
                    else {
                        dp[i][j][l] = max(dp[i - 1][j][l], prices[i] + dp[i - 1][j - 1][0]);
                    }
                }
            }
        }

        return dp[n - 1][k][0];
        
    }
};