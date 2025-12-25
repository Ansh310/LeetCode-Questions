class Solution {
public:
    long long maximumHappinessSum(vector<int>& happiness, int k) {
        sort(happiness.begin(), happiness.end(), greater<int>()); 

        long long sum = 0; int dec = 0;

        for(int i = 0; i < k; i++) {

            sum += max(happiness[i] - dec, 0);
            dec++;
            
        }
        return sum;
    }
};