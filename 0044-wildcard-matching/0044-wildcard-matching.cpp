class Solution {
public:
    bool check(string s, string p, int i, int j) {
        if(i == s.size() && j == p.size()) {
            return true;
        }

        if(i > s.size() || j > p.size()) return false;

        if(p[j] != '*' && p[j] != '?' && (s[i] != p[j])) return false;

        if(p[j] == '*') {
            return check(s, p, i, j + 1) || check(s, p, i + 1, j);
        }

        return check(s, p, i + 1, j + 1);


    }
    bool isMatch(string s, string p) {
        //return check(s, p, 0, 0);

        int n = s.size(), m = p.size();
        vector<vector<int>> dp(n + 1, vector<int>(m + 1));

        dp[0][0] = 1;

        for(int i = 1; i <= n; i++) dp[i][0]= 0;

        for(int j = 1; j <= m; j++) {
            dp[0][j] = dp[0][j - 1] && p[j - 1] == '*';
        }

        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= m; j++) {
                if(s[i - 1] == p[j - 1] || p[j - 1] == '?') {
                    dp[i][j] = dp[i - 1][j - 1];
                }

                else if(p[j - 1] == '*') {
                    dp[i][j] = dp[i - 1][j] || dp[i][j - 1];
                }

                else dp[i][j] = 0;
            }
        }

        return dp[n][m];
    }
};