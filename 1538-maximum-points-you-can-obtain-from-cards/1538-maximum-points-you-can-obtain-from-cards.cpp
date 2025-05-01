class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int maxsum = 0, n = cardPoints.size(), st = 0, end = n - k - 1, total_sum = 0, sum = 0;

        for(int i = 0; i < n; i++) total_sum += cardPoints[i];

        for(int i = 0; i <= end; i++) sum += cardPoints[i];

        while(end < n) {
            maxsum = max(maxsum, total_sum - sum);

            sum -= cardPoints[st]; 
            st++; end++;
            if(end < n) sum += cardPoints[end];
        }
        return maxsum;
    }
};