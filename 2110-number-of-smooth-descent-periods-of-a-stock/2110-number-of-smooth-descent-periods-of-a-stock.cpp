class Solution {
public:
    long long getDescentPeriods(vector<int>& prices) {
        int n = prices.size(), i = 0;
        long long ans = 0;

        while(i < n) {
            int st = i;
            while(i + 1 < n && prices[i] - prices[i + 1] == 1) i++;

            long long len = i - st + 1;

            ans += len * (len + 1) / 2;
            i++;

        }
        return ans;
    }
};