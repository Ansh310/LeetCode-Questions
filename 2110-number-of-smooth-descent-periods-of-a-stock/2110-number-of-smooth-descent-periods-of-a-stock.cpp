class Solution {
public:
    long long getDescentPeriods(vector<int>& prices) {
        int n = prices.size();
        long long ans = 0;
        int st = 0;

        for(int i = 0; i < n; i++) {
            
            if(i == 0 || prices[i] - prices[i - 1] != -1) st = i;

            long long len = i - st + 1;

            ans += len;

        }
        return ans;
    }
};