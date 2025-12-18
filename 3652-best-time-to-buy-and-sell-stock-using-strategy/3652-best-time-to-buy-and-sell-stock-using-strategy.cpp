class Solution {
public:
    long long maxProfit(vector<int>& prices, vector<int>& strategy, int k) {
        int n = prices.size();
        vector<long long> prefixSum(n);

        //calculating prefixSum array
        prefixSum[0] = prices[0] * strategy[0];
        for(int i = 1; i < n; i++) {
            prefixSum[i] += prefixSum[i - 1] + (long long)prices[i] * strategy[i];
        }

        long long maxProfit = prefixSum[n - 1], sum = 0;
        int st = 0, end= 0;

        while(end < n && end - st + 1 < k) end++;

        while(end < n) {
        
            long long temp_sum = (st == 0 ? 0 : prefixSum[st - 1]);

            for(int l = st + k / 2; l <= end; l++) {
                temp_sum += prices[l];
            }

            temp_sum += prefixSum[n - 1] - prefixSum[end];

            if(temp_sum > maxProfit) maxProfit = temp_sum;

            end++;
            st++;
        }

        return maxProfit;
    }
};