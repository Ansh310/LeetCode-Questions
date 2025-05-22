class Solution {
public:
    bool checkValidString(string s) {
        int n = s.size();
        vector<vector<bool>> dp(n + 1, vector<bool>(n + 1, false));

        dp[n][0] = true;

        for(int i = n - 1; i >= 0; i--) {
            for(int cnt = 0; cnt <= n; cnt++) {
                if(s[i] == '(') {
                    dp[i][cnt] = dp[i + 1][cnt + 1];
                }
                else if(s[i] == ')' && cnt > 0) {
                    dp[i][cnt] = dp[i + 1][cnt - 1];
                }
                else if(s[i] == '*') {
                    dp[i][cnt] = dp[i + 1][cnt] || dp[i + 1][cnt + 1];
                    if(cnt > 0) dp[i][cnt] = dp[i][cnt] || dp[i + 1][cnt - 1];
                }
            }
        }
        return dp[0][0];
    }
};