class Solution {
public:
    long long maximumHappinessSum(vector<int>& happiness, int k) {
        sort(happiness.begin(), happiness.end()); int n = happiness.size();

        long long sum = 0; int dec = 0;

        for(int i = n - 1; i >= 0; i--) {
            
            if(happiness[i] - dec > 0) happiness[i] -= dec;
            else happiness[i] = 0;

            sum = sum + happiness[i];
            dec++;
            k--;
            if(k == 0) break;
        }
        return sum;
    }
};