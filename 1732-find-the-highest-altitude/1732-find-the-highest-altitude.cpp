class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int maxi = 0;
        int n = gain.size(), prev = 0;

        for(int i = 1; i <= n; i++) {
            prev = prev + gain[i - 1];
            maxi = max(maxi, prev);
        }

        return maxi;
    }
};