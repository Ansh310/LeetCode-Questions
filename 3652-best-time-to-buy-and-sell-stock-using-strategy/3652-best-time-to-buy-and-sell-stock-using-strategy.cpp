class Solution {
public:
    long long maxProfit(vector<int>& prices, vector<int>& strategy, int k) {
        int n = prices.size();
        vector<long long> prefixSum(n + 1), prices_sum(n + 1);

        //calculating prefixSum array
        
        for(int i = 0; i < n; i++) {
            prefixSum[i + 1] += prefixSum[i] + prices[i] * strategy[i];
            prices_sum[i + 1] += prices_sum[i] + prices[i];
        }

        long long maxProfit = prefixSum[n], sum = 0;
        int st = 0;

        while(st + k - 1 < n) {
        
            long long temp_sum = prefixSum[st];

            temp_sum += prices_sum[st + k] - prices_sum[st + k/2];

            temp_sum += prefixSum[n] - prefixSum[st + k];

            if(temp_sum > maxProfit) maxProfit = temp_sum;
            st++;
        }

        return maxProfit;
    }
};